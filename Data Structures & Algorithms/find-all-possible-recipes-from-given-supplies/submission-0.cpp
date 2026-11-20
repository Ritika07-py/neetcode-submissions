class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients,
                                      vector<string>& supplies) {
            unordered_map<string, vector<int>> waiting;
            vector<int> remaining(recipes.size());
            for (int i = 0; i < recipes.size(); i++) {
                remaining[i] = ingredients[i].size();
                for (auto& item : ingredients[i]) waiting[item].push_back(i);
            }
            queue<string> q;
            for (auto& s : supplies) q.push(s);
            vector<string> answer;
            while (!q.empty()) {
                auto item = q.front();
                q.pop();
                for (int i : waiting[item])
                    if (--remaining[i] == 0) {
                        answer.push_back(recipes[i]);
                        q.push(recipes[i]);
                    }
            }
            return answer;
        }
};
