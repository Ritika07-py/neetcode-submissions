class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top=0,bottom=0;for(int v:grid[0])top+=v;long long answer=top;for(int c=0;c<grid[0].size();c++){top-=grid[0][c];answer=min(answer,max(top,bottom));bottom+=grid[1][c];}return answer;
    }
};
