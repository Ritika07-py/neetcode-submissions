class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        unordered_set<int> res;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) res.insert(i);

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int& nei : adj[node]) {
                if (!visited[nei]) dfs(nei);
                res.erase(nei);
            }
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(i);
        }
        return vector<int>(res.begin(), res.end());
    }
};