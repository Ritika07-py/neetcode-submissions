class Solution {
private:
    vector<int> color;

    bool dfs(vector<vector<int>>& graph, int i, int c) {
        color[i] = c;
        for (int nei : graph[i]) {
            if (color[nei] == c) {
                return false;
            }
            if (color[nei] == 0 && !dfs(graph, nei, -c)) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, 0); // Map node i -> odd=1, even=-1

        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && !dfs(graph, i, 1)) {
                return false;
            }
        }
        return true;
    }
};