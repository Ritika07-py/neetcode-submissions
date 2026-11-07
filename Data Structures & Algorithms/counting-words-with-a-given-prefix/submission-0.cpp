class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int N = pref.size(), res = 0;

        for (auto &w : words) {
            if ((int)w.size() < N) continue;
            int inc = 1;
            for (int i = 0; i < N; i++) {
                if (w[i] != pref[i]) {
                    inc = 0;
                    break;
                }
            }
            res += inc;
        }

        return res;
    }
};