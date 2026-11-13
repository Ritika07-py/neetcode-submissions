class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        if (maxFreq > (s.size() + 1) / 2) {
            return "";
        }

        string res;
        while (res.size() < s.size()) {
            int maxIdx = findMaxIndex(freq);
            char maxChar = 'a' + maxIdx;
            res += maxChar;
            freq[maxIdx]--;

            if (freq[maxIdx] == 0) {
                continue;
            }

            int tmp = freq[maxIdx];
            freq[maxIdx] = INT_MIN;
            int nextMaxIdx = findMaxIndex(freq);
            char nextMaxChar = 'a' + nextMaxIdx;
            res += nextMaxChar;
            freq[maxIdx] = tmp;
            freq[nextMaxIdx]--;
        }

        return res;
    }

private:
    int findMaxIndex(const vector<int>& freq) {
        int maxIdx = 0;
        for (int i = 1; i < freq.size(); i++) {
            if (freq[i] > freq[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }
};