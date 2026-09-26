class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> count;
        for (char c : chars) {
            count[c]++;
        }
        int res = 0;
        for (const string& w : words) {
            unordered_map<char, int> curWord;
            for (char c : w) {
                curWord[c]++;
            }
            bool good = true;
            for (const auto& p : curWord) {
                if (p.second > count[p.first]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                res += w.size();
            }
        }
        return res;
    }
};