class Solution {
    int ROWS, COLS;
    vector<vector<int>> directions;
    vector<vector<bool>> visit;

public:
    int closedIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        visit.assign(ROWS, vector<bool>(COLS, false));

        int res = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 0 && !visit[r][c]) {
                    if (dfs(grid, r, c)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }

private:
    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r == ROWS || c == COLS) {
            return false;
        }
        if (grid[r][c] == 1 || visit[r][c]) {
            return true;
        }

        visit[r][c] = true;
        bool res = true;
        for (auto& d : directions) {
            if (!dfs(grid, r + d[0], c + d[1])) {
                res = false;
            }
        }
        return res;
    }
};