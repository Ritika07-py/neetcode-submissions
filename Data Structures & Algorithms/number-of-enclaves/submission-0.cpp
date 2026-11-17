class Solution {
public:
    int ROWS, COLS;
    vector<vector<bool>> visit;
    vector<vector<int>> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int numEnclaves(vector<vector<int>>& grid) {
        this->ROWS = grid.size();
        this->COLS = grid[0].size();
        this->visit = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        int land = 0, borderLand = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                land += grid[r][c];
                if (grid[r][c] == 1 && !visit[r][c] &&
                    (r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1)) {
                    borderLand += dfs(r, c, grid);
                }
            }
        }
        return land - borderLand;
    }

private:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r == ROWS || c == COLS ||
            grid[r][c] == 0 || visit[r][c]) {
            return 0;
        }
        visit[r][c] = true;
        int res = 1;
        for (auto& d : direct) {
            res += dfs(r + d[0], c + d[1], grid);
        }
        return res;
    }
};