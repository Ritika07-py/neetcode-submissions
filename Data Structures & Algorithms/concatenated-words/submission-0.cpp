class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> res;

        for (const string& w : words) {
            if (dfs(w, wordSet)) {
                res.push_back(w);
            }
        }
        return res;
    }

private:
    bool dfs(const string& word, unordered_set<string>& wordSet) {
        for (int i = 1; i < word.size(); i++) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);

            if ((wordSet.count(prefix) && wordSet.count(suffix)) ||
                (wordSet.count(prefix) && dfs(suffix, wordSet))) {
                return true;
            }
        }
        return false;
    }
};