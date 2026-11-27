class Solution {
    public:
        int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
            vector<vector<int>> graph(n);
            for (auto& e : edges) {
                graph[e[0]].push_back(e[1]);
                graph[e[1]].push_back(e[0]);
            }
            vector<int> parent(n, -1), depth(n), order = {0};
            for (int at = 0; at < order.size(); at++) {
                int u = order[at];
                for (int v : graph[u])
                    if (v != parent[u]) {
                        parent[v] = u;
                        depth[v] = depth[u] + 1;
                        order.push_back(v);
                    }
            }
            vector<int> remainders(n);
            for (int i = 0; i < n; i++) remainders[i] = values[i] % k;
            int answer = 0;
            for (int at = order.size() - 1; at >= 0; at--) {
                int u = order[at];
                if (remainders[u] == 0) answer++;
                if (parent[u] != -1)
                    remainders[parent[u]] = (remainders[parent[u]] + remainders[u]) % k;
            }
            return answer;
        }
};
