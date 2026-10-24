class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int,int>,long long> counts;long long answer=0;for(const auto& p:rectangles){int a=p[0],b=p[1];while(b){int t=a%b;a=b;b=t;}pair<int,int> key={p[0]/a,p[1]/a};answer+=counts[key]++;}return answer;
    }
};
