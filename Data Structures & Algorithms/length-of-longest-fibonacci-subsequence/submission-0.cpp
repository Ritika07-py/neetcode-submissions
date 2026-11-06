class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(),best=0;
        vector<vector<int>> dp(n,vector<int>(n,2));
        for (int k=2;k<n;k++) {
            int left=0,right=k-1;
            while (left<right) { int total=arr[left]+arr[right];
                if (total<arr[k]) left++; else if (total>arr[k]) right--;
                else { dp[right][k]=dp[left][right]+1; best=max(best,dp[right][k]); left++; right--; }
            }
        }
        return best;
    }
};
