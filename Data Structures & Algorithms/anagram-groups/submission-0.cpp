	#include <vector>

	#include <string>

	#include <unordered_map>

	#include <algorithm>

	 

	using namespace std;

	 

	class Solution {

	public:

	    vector<vector<string>> groupAnagrams(vector<string>& strs) {

	        unordered_map<string, vector<string>> ans;

	        for (const string& s : strs) {

	            string key = s;

	            sort(key.begin(), key.end());

	            ans[key].push_back(s);

	        }

	        vector<vector<string>> result;

	        for (const auto& entry : ans) {

	            result.push_back(entry.second);

	        }

	        return result;

	        // Time: O(n * m log m), n is the number of strings, m is the length of largest string

	        // Space: O(n * m)

	    }

	};
