class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '1') count++;
        }

        string result((count - 1), '1');
        result += string(s.length() - count, '0');
        result += '1';

        return result;
    }
};