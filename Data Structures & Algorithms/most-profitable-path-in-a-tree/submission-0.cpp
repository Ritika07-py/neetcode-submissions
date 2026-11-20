class Solution {
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
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
            vector<int> bobtime(n, n);
            for (int u = bob, t = 0; u != -1; u = parent[u], t++) bobtime[u] = t;
            vector<int> profit(n);
            int answer = -1000000000;
            for (int u : order) {
                int gain = depth[u] < bobtime[u]    ? amount[u]
                           : depth[u] == bobtime[u] ? amount[u] / 2
                                                    : 0;
                profit[u] = gain + (u == 0 ? 0 : profit[parent[u]]);
                if (u != 0 && graph[u].size() == 1) answer = max(answer, profit[u]);
            }
            return answer;
        }
};

