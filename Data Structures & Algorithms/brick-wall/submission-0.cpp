class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int m = 0;
        for (int brick : wall[0]) {
            m += brick;
        }

        vector<vector<int>> gaps(n);
        for (int i = 0; i < n; i++) {
            int gap = 0;
            for (int brick : wall[i]) {
                gap += brick;
                gaps[i].push_back(gap);
            }
        }

        int res = n;
        for (int line = 1; line < m; line++) {
            int cuts = 0;
            for (int i = 0; i < n; i++) {
                if (find(gaps[i].begin(), gaps[i].end(), line) == gaps[i].end()) {
                    cuts++;
                }
            }
            res = min(res, cuts);
        }

        return res;
    }
};