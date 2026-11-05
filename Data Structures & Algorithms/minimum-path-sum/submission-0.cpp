class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return dfs(0, 0, grid);
    }

    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r == grid.size() - 1 && c == grid[0].size() - 1) {
            return grid[r][c];
        }
        if (r == grid.size() || c == grid[0].size()) {
            return INT_MAX;
        }
        return grid[r][c] + min(dfs(r + 1, c, grid), dfs(r, c + 1, grid));
    }
};