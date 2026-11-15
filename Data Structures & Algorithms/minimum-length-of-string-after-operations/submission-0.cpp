class Solution {
public:
    int minimumLength(string s) {
        vector<int> counts(26);
        for (char c : s) counts[c - 'a']++;
        int answer = 0;
        for (int n : counts) if (n > 0) answer += n % 2 == 1 ? 1 : 2;
        return answer;
    }
};
