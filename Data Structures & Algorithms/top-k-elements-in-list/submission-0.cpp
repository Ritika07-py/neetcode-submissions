	#include <vector>

	#include <unordered_map>

	#include <queue>

	#include <algorithm>

	using namespace std;

	 

	class Solution {

	public:

	    vector<int> topKFrequent(vector<int>& nums, int k) {

	        unordered_map<int, int> countMap;

	        for (int num : nums) {

	            countMap[num]++;

	        }

	        

	        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {

	            return a.second > b.second;

	        };

	        

	        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

	        

	        for (auto& entry : countMap) {

	            if (minHeap.size() < k) {

	                minHeap.push(entry);

	            } else {

	                minHeap.push(entry);

	                minHeap.pop();

	            }

	        }

	        

	        vector<int> topK;

	        while (!minHeap.empty()) {

	            topK.push_back(minHeap.top().first);

	            minHeap.pop();

	        }

	        

	        reverse(topK.begin(), topK.end());

	        return topK;

	    }

	};

	 
