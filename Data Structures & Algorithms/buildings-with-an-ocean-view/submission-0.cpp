class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = i + 1; j < n; j++) {
                if (heights[i] <= heights[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(i);
        }

        return res;
    }
};