class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        array<int,26> need{},window{};for(char c:p)need[c-'a']++;vector<int> answer;for(int i=0;i<(int)s.size();i++){window[s[i]-'a']++;if(i>=(int)p.size())window[s[i-p.size()]-'a']--;if(i+1>=(int)p.size()&&need==window)answer.push_back(i+1-p.size());}return answer;
    }
};
