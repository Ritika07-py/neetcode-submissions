class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increase = true;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                increase = false;
                break;
            }
        }
        if (increase) {
            return true;
        }

        bool decrease = true;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                decrease = false;
                break;
            }
        }
        return decrease;
    }
};