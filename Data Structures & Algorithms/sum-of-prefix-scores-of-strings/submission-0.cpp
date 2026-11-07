class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<int,int> edges;vector<int> counts(1),answer;for(const string& word:words){int node=0;for(char c:word){int key=node*26+c-'a';if(!edges.count(key)){edges[key]=counts.size();counts.push_back(0);}node=edges[key];counts[node]++;}}for(const string& word:words){int node=0,score=0;for(char c:word){node=edges[node*26+c-'a'];score+=counts[node];}answer.push_back(score);}return answer;
    }
};
