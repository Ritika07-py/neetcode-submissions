class Solution {
private:
    int res = 0;

    int dfs(const string& s, int i) {
        if (i == s.length()) {
            return 0;
        }

        int cur = dfs(s, i + 1);
        if (s[i] == '(') {
            cur += 1;
        } else if (s[i] == ')') {
            cur -= 1;
        }

        res = max(res, abs(cur));
        return cur;
    }

public:
    int maxDepth(string s) {
        dfs(s, 0);
        return res;
    }
};