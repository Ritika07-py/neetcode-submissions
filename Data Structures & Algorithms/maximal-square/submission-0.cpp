class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == '0') {
                    continue;
                }
                int k = 1;
                while (true) {
                    if (r + k > m || c + k > n) {
                        break;
                    }
                    bool flag = true;

                    for (int i = r; i < r + k; i++) {
                        if (matrix[i][c + k - 1] == '0') {
                            flag = false;
                            break;
                        }
                    }
                    for (int j = c; j < c + k; j++) {
                        if (matrix[r + k - 1][j] == '0') {
                            flag = false;
                            break;
                        }
                    }

                    if (!flag) {
                        break;
                    }
                    res = max(res, k * k);
                    k++;
                }
            }
        }

        return res;
    }
};