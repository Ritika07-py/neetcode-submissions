class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(nums2.size()+1); for(int x:nums1) { int diagonal=0; for(int j=1;j<=nums2.size();j++) { int old=dp[j]; dp[j]=x==nums2[j-1]?diagonal+1:max(dp[j],dp[j-1]); diagonal=old; } } return dp.back();
    }
};
