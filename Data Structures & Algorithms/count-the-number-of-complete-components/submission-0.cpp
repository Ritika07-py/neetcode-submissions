class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> graph(n);
            for (auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            vector<bool> seen(n);
            int answer = 0;
            for (int start = 0; start < n; start++) {
                if (seen[start]) continue;
                vector<int> queue{start};
                seen[start] = true;
                int degree = 0;
                for (int at = 0; at < queue.size(); at++) {
                    int u = queue[at];
                    degree += graph[u].size();
                    for (int v : graph[u])
                        if (!seen[v]) {
                            seen[v] = true;
                            queue.push_back(v);
                        }
                }
                int size = queue.size();
                if (degree == size * (size - 1)) answer++;
            }
            return answer;
        }
};
