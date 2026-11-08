class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<int> dp(matrix[0].size()+1);int answer=0;for(const auto& row:matrix){int diagonal=0;for(int j=1;j<=row.size();j++){int above=dp[j];dp[j]=row[j-1]?1+min({above,dp[j-1],diagonal}):0;answer+=dp[j];diagonal=above;}}return answer;
    }
};
