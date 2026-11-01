class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return dfs(nums, target);
    }

    int dfs(vector<int>& nums, int total) {
        if (total == 0) {
            return 1;
        }

        int res = 0;
        for (int num : nums) {
            if (total < num) {
                break;
            }
            res += dfs(nums, total - num);
        }
        return res;
    }
};