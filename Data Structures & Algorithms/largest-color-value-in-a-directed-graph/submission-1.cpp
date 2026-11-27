class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<bool> visit;

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        adj.assign(n, vector<int>());
        visit.assign(n, false);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                int cnt = dfs(i, c, colors);
                if (cnt == 1e9) return -1;
                res = max(res, cnt);
            }
        }
        return res;
    }

private:
    int dfs(int node, int c, string& colors) {
        if (visit[node]) return 1e9;

        visit[node] = true;
        int clrCnt = 0;
        for (int nei : adj[node]) {
            int cur = dfs(nei, c, colors);
            if (cur == 1e9) return cur;
            clrCnt = max(clrCnt, cur);
        }
        visit[node] = false;
        return clrCnt + ((colors[node] - 'a') == c ? 1 : 0);
    }
};