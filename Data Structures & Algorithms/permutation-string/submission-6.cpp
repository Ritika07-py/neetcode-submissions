class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Track the number of unique characters that still need to be matched
        int uniqueCharsToMatch = 0;
      
        // Frequency array to track the difference between required and current window characters
        // Positive: need more of this character, Negative: have excess of this character
        int charFrequencyDiff[26] = {0};
      
        // Build the frequency map for s1 (the pattern we're looking for)
        for (char ch : s1) {
            int charIndex = ch - 'a';
            if (++charFrequencyDiff[charIndex] == 1) {
                // This character wasn't needed before, now it is
                ++uniqueCharsToMatch;
            }
        }
      
        int patternLength = s1.size();
        int textLength = s2.size();
      
        // Sliding window approach
        for (int windowEnd = 0; windowEnd < textLength; ++windowEnd) {
            // Add current character to the window
            int currentCharIndex = s2[windowEnd] - 'a';
            if (--charFrequencyDiff[currentCharIndex] == 0) {
                // This character's frequency now matches exactly
                --uniqueCharsToMatch;
            }
          
            // Remove the leftmost character if window size exceeds pattern length
            if (windowEnd >= patternLength) {
                int leftCharIndex = s2[windowEnd - patternLength] - 'a';
                if (++charFrequencyDiff[leftCharIndex] == 1) {
                    // This character was balanced, now we need one more
                    ++uniqueCharsToMatch;
                }
            }
          
            // Check if all characters are matched (permutation found)
            if (uniqueCharsToMatch == 0) {
                return true;
            }
        }
      
        return false;
    }
};
