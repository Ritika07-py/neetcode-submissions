class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int res = -1;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[i] + prices[j] <= money) {
                    res = max(res, money - prices[i] - prices[j]);
                }
            }
        }
        return res == -1 ? money : res;
    }
};