class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (a == b) continue;
                for (int c = 0; c < n; c++) {
                    if (a == c || b == c) continue;
                    for (int d = 0; d < n; d++) {
                        if (a == d || b == d || c == d) continue;
                        res = max(res, nums[a] * nums[b] - nums[c] * nums[d]);
                    }
                }
            }
        }
        return res;
    }
};