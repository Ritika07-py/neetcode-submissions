class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int maxi = 0, cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (min(heights[i], heights[j]) > maxi) {
                    cnt++;
                }
                maxi = max(maxi, heights[j]);
            }
            res[i] = cnt;
        }
        return res;
    }
};