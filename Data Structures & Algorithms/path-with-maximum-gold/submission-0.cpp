class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int getMaximumGold(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int res = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] != 0) {
                    vector<vector<bool>> visit(ROWS, vector<bool>(COLS, false));
                    res = max(res, dfs(grid, r, c, visit));
                }
            }
        }
        return res;
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visit) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0 || visit[r][c]) {
            return 0;
        }

        visit[r][c] = true;
        int res = grid[r][c];

        for (auto& d : directions) {
            res = max(res, grid[r][c] + dfs(grid, r + d[0], c + d[1], visit));
        }

        visit[r][c] = false;
        return res;
    }
};