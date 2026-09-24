class Solution {
public:
    string removeDuplicates(string s, int k) {
        while (s.length()) {
            bool flag = false;
            char cur = s[0];
            int cnt = 1;

            for (int i = 1; i < s.size(); i++) {
                if (cur != s[i]) {
                    cnt = 0;
                    cur = s[i];
                }
                cnt++;
                if (cnt == k) {
                    s = s.substr(0, i - cnt + 1) + s.substr(i + 1);
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                break;
            }
        }

        return s;
    }
};