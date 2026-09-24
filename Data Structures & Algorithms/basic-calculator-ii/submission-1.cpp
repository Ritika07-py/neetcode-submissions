class Solution {
public:
    int calculate(string s) {
        int total = 0, prev = 0, num = 0;
        char op = '+';
        int n = s.size(), i = 0;
        while (i <= n) {
            char ch = i < n ? s[i] : '+';
            if (ch == ' ') {
                i++;
                continue;
            }
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else {
                if (op == '+') {
                    total += prev;
                    prev = num;
                } else if (op == '-') {
                    total += prev;
                    prev = -num;
                } else if (op == '*') {
                    prev = prev * num;
                } else {
                    prev = prev / num;
                }
                op = ch;
                num = 0;
            }
            i++;
        }
        total += prev;
        return total;
    }
};