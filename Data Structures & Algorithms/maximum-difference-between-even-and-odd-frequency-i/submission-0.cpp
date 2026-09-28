class Solution {
public:
    int maxDifference(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int res = INT_MIN;
        for (int odd : count) {
            if (odd == 0 || odd % 2 == 0) continue;
            for (int even : count) {
                if (even == 0 || even % 2 == 1) continue;
                res = max(res, odd - even);
            }
        }
        return res;
    }
};