class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            unordered_map<int, int> leftCnt, rightCnt;
            for (int l = 0; l <= i; l++) {
                leftCnt[nums[l]]++;
            }
            for (int r = i + 1; r < n; r++) {
                rightCnt[nums[r]]++;
            }

            for (auto& [num, cnt] : leftCnt) {
                if (cnt > (i + 1) / 2 && rightCnt[num] > (n - i - 1) / 2) {
                    return i;
                }
            }
        }

        return -1;
    }
};