class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        int res = -1;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 0) {
                    res = max(res, bfs(grid, r, c, N));
                    if (res == -1) return res;
                }
            }
        }
        return res;
    }

private:
    const int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int bfs(vector<vector<int>>& grid, int row, int col, int N) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visit(N, vector<bool>(N, false));
        q.push({row, col});
        visit[row][col] = true;
        int dist = 0;

        while (!q.empty()) {
            dist++;
            for (int i = q.size(); i > 0; i--) {
                auto [r, c] = q.front();q.pop();

                for (auto& d : direct) {
                    int newR = r + d[0], newC = c + d[1];
                    if (newR < 0 || newC < 0 || newR >= N || newC >= N || visit[newR][newC])
                        continue;
                    if (grid[newR][newC] == 1)
                        return dist;

                    visit[newR][newC] = true;
                    q.push({newR, newC});
                }
            }
        }
        return -1;
    }
};