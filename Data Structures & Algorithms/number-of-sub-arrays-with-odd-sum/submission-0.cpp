class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), res = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int curSum = 0;
            for (int j = i; j < n; j++) {
                curSum += arr[j];
                if (curSum % 2 != 0) {
                    res = (res + 1) % mod;
                }
            }
        }

        return res;
    }
};