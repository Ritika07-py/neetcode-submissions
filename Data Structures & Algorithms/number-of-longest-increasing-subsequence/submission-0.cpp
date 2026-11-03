class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lengths(n);
        vector<long long> counts(n);
        fill(lengths.begin(),lengths.end(),1);
        fill(counts.begin(),counts.end(),1);
        int best = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (lengths[j]+1 > lengths[i]) { lengths[i] = lengths[j]+1; counts[i] = counts[j]; }
                    // Cap intermediate counts: only the final answer is guaranteed to fit in 32 bits.
                    else if (lengths[j]+1 == lengths[i]) counts[i] = min(2147483647LL,counts[i]+counts[j]);
                }
            }
            best = max(best,lengths[i]);
        }
        long long answer = 0;
        for (int i = 0; i < n; i++) if (lengths[i] == best) answer += counts[i];
        return (int)answer;
    }
};
