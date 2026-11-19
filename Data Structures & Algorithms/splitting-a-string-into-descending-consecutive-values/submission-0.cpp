class Solution {
public:
    bool splitString(string s) {
        vector<long long> splits;
        return dfs(s, 0, splits);
    }

private:
    bool isValid(vector<long long>& splits) {
        for (int i = 1; i < splits.size(); i++) {
            if (splits[i] != splits[i - 1] - 1) {
                return false;
            }
        }
        return splits.size() > 1;
    }

    bool dfs(string& s, int i, vector<long long>& splits) {
        if (i == s.size()) {
            return isValid(splits);
        }
        unsigned long long num = 0;
        for (int j = i; j < s.size(); j++) {
            num = num * 10 + (s[j] - '0');
            splits.push_back(num);
            if (dfs(s, j + 1, splits)) {
                return true;
            }
            splits.pop_back();
        }
        return false;
    }
};
