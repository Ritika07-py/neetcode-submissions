class Solution {
    public:
        int slidingPuzzle(vector<vector<int>>& board) {
            string start;
            for (auto& row : board)
                for (int x : row) start += char('0' + x);
            vector<vector<int>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
            queue<string> q;
            q.push(start);
            unordered_set<string> seen{start};
            for (int moves = 0; !q.empty(); moves++) {
                int size = q.size();
                while (size--) {
                    string state = q.front();
                    q.pop();
                    if (state == "123450") return moves;
                    int zero = state.find('0');
                    for (int j : adj[zero]) {
                        string next = state;
                        swap(next[zero], next[j]);
                        if (seen.insert(next).second) q.push(next);
                    }
                }
            }
            return -1;
        }
};
