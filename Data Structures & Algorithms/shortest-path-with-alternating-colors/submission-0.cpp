class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        for (auto& edge : redEdges) red[edge[0]].push_back(edge[1]);
        for (auto& edge : blueEdges) blue[edge[0]].push_back(edge[1]);

        vector<int> answer(n, -1);
        queue<vector<int>> q;
        q.push({0, 0, -1});
        unordered_set<string> visit;
        visit.insert("0,-1");

        while (!q.empty()) {
            vector<int> nodeData = q.front();
            q.pop();
            int node = nodeData[0], length = nodeData[1], edgeColor = nodeData[2];

            if (answer[node] == -1) answer[node] = length;

            if (edgeColor != 0) {
                for (int nei : red[node]) {
                    string key = to_string(nei) + ",0";
                    if (visit.insert(key).second) {
                        q.push({nei, length + 1, 0});
                    }
                }
            }
            if (edgeColor != 1) {
                for (int nei : blue[node]) {
                    string key = to_string(nei) + ",1";
                    if (visit.insert(key).second) {
                        q.push({nei, length + 1, 1});
                    }
                }
            }
        }
        return answer;
    }
};