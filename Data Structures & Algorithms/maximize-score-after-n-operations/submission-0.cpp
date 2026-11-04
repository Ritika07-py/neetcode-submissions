class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size(),size=1<<n;vector<vector<int>> g(n,vector<int>(n));for(int i=0;i<n;i++)for(int j=0;j<n;j++){int a=nums[i],b=nums[j];while(b){int t=a%b;a=b;b=t;}g[i][j]=a;}vector<int> dp(size);for(int mask=0;mask<size;mask++){int used=__builtin_popcount(mask);if(used%2)continue;int op=used/2+1;for(int i=0;i<n;i++){if(mask&(1<<i))continue;for(int j=i+1;j<n;j++){if(mask&(1<<j))continue;int next=mask|(1<<i)|(1<<j);dp[next]=max(dp[next],dp[mask]+op*g[i][j]);}}}return dp.back();
    }
};
