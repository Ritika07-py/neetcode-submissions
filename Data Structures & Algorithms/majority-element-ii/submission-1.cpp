class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_set<int> res;
        for (int num : nums) {
            int count = 0;
            for (int i : nums) {
                if (i == num) count++;
            }
            if (count > nums.size() / 3) {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};