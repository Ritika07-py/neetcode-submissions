class Solution {
    unordered_map<long long, int> dp;

public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return dfs(0, 0, nums, p);
    }

private:
    int dfs(int i, int pairs, vector<int>& nums, int p) {
        if (pairs == p) return 0;
        if (i >= nums.size() - 1) return INT_MAX;
        long long key = i;
        key = (key << 31) | pairs;
        if (dp.count(key)) return dp[key];

        int take = max(nums[i + 1] - nums[i], dfs(i + 2, pairs + 1, nums, p));
        int skip = dfs(i + 1, pairs, nums, p);

        return dp[key] = min(take, skip);
    }
};