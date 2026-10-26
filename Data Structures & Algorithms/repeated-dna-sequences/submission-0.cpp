class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen,repeated;for(int i=0;i+10<=s.size();i++){string word=s.substr(i,10);if(!seen.insert(word).second)repeated.insert(word);}return vector<string>(repeated.begin(),repeated.end());
    }
};
