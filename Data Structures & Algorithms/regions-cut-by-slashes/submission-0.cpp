class Solution {
    public:
        int regionsBySlashes(vector<string>& grid) {
            int n = grid.size(), w = n * 3;
            vector<vector<bool>> seen(w, vector<bool>(w));
            for (int r = 0; r < n; r++)
                for (int c = 0; c < n; c++) {
                    char ch = grid[r][c];
                    if (ch != ' ')
                        for (int k = 0; k < 3; k++)
                            seen[r * 3 + k][c * 3 + (ch == '/' ? 2 - k : k)] = true;
                }
            int answer = 0;
            vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (int r = 0; r < w; r++)
                for (int c = 0; c < w; c++) {
                    if (seen[r][c]) continue;
                    answer++;
                    seen[r][c] = true;
                    vector<int> stack{r * w + c};
                    while (!stack.empty()) {
                        int x = stack.back();
                        stack.pop_back();
                        for (auto [dr, dc] : dirs) {
                            int a = x / w + dr, b = x % w + dc;
                            if (a >= 0 && a < w && b >= 0 && b < w && !seen[a][b]) {
                                seen[a][b] = true;
                                stack.push_back(a * w + b);
                            }
                        }
                    }
                }
            return answer;
        }
};
