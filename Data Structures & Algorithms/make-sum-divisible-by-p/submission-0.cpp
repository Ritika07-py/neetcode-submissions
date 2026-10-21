class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totSum = 0;
        for (int num : nums) totSum += num;

        if (totSum % p == 0) return 0;

        for (int l = 1; l < n; l++) {
            long long curSum = 0;
            for (int i = 0; i < n; i++) {
                curSum += nums[i];
                if (i >= l) curSum -= nums[i - l];

                long long remainSum = totSum - curSum;
                if (remainSum % p == 0) return l;
            }
        }

        return -1;
    }
};