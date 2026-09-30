class NumArray {
private:
    const vector<int>& nums;

public:
    NumArray(const vector<int>& nums) : nums(nums) {}

    int sumRange(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; i++) {
            res += nums[i];
        }
        return res;
    }
};