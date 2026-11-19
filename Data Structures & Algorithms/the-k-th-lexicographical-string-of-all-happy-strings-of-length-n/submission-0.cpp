class Solution {
    public:
        string getHappyString(int n, int k) {
            if (k > 3 * (1 << (n - 1))) return "";
            string answer;
            for (int i = 0; i < n; i++) {
                int block = 1 << (n - i - 1);
                for (char c : string("abc")) {
                    if (i > 0 && c == answer.back()) continue;
                    if (k > block)
                        k -= block;
                    else {
                        answer += c;
                        break;
                    }
                }
            }
            return answer;
        }
};
