class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
int n=target.size(),full=(1<<n)-1;vector<array<int,26>> counts(stickers.size());for(int i=0;i<stickers.size();i++)for(char c:stickers[i])counts[i][c-'a']++;vector<int> dp(full+1,16);dp[0]=0;for(int mask=0;mask<full;mask++){if(dp[mask]==16)continue;int first=0;while(mask&(1<<first))first++;for(auto row:counts){if(!row[target[first]-'a'])continue;int next=mask;for(int j=0;j<n;j++){int c=target[j]-'a';if(!(next&(1<<j))&&row[c]){next|=1<<j;row[c]--;}}dp[next]=min(dp[next],dp[mask]+1);}}return dp[full]==16?-1:dp[full];
}
};
