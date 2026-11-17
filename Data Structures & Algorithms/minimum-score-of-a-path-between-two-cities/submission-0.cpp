class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<bool> visit;
    int res;

    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n + 1);
        visit.resize(n + 1, false);
        res = INT_MAX;

        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        dfs(1);
        return res;
    }

    void dfs(int node) {
        if (visit[node]) return;
        visit[node] = true;

        for (auto& edge : adj[node]) {
            res = min(res, edge.second);
            dfs(edge.first);
        }
    }
};