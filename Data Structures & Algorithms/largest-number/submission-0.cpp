class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        string res;
        while (!arr.empty()) {
            int maxi = 0;
            for (int i = 1; i < arr.size(); i++) {
                if (arr[i] + arr[maxi] > arr[maxi] + arr[i]) {
                    maxi = i;
                }
            }
            res += arr[maxi];
            arr.erase(arr.begin() + maxi);
        }

        return res[0] == '0' ? "0" : res;
    }
};