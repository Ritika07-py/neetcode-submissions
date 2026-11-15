class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size()<k) return false; vector<int> counts(26); for (char c:s) counts[c-97]++; int odd=0; for (int x:counts) odd+=x%2; return odd<=k;
    }
};
