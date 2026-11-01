class Solution {
public:
    int numSquares(int n) {
        return dfs(n);
    }

private:
    int dfs(int target) {
        if (target == 0) {
            return 0;
        }

        int res = target;
        for (int i = 1; i * i <= target; i++) {
            res = min(res, 1 + dfs(target - i * i));
        }
        return res;
    }
};