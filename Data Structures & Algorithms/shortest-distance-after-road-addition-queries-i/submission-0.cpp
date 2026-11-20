class Solution {
    public:
        vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
            vector<vector<int>> graph(n);
            for (int i = 0; i + 1 < n; i++) graph[i].push_back(i + 1);
            vector<int> answer;
            for (auto& q : queries) {
                graph[q[0]].push_back(q[1]);
                vector<int> dist(n, -1), queue = {0};
                dist[0] = 0;
                for (int at = 0; at < queue.size(); at++) {
                    int u = queue[at];
                    for (int v : graph[u])
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            queue.push_back(v);
                        }
                }
                answer.push_back(dist[n - 1]);
            }
            return answer;
        }
};
