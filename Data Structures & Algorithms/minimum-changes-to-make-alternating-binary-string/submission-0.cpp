class Solution {
public:
    int minOperations(string s) {
        int cur = 0, cnt1 = 0;
        for (char c : s) {
            if (c - '0' != cur) {
                cnt1++;
            }
            cur ^= 1;
        }

        cur = 1;
        int cnt2 = 0;
        for (char c : s) {
            if (c - '0' != cur) {
                cnt2++;
            }
            cur ^= 1;
        }

        return min(cnt1, cnt2);
    }
};