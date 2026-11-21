class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size(), n = grid[0].size(), total = m * n;
            vector<int> cells(total), order(queries.size()), parent(total), size(total, 1),
                answer(queries.size());
            vector<bool> active(total);
            iota(cells.begin(), cells.end(), 0);
            iota(order.begin(), order.end(), 0);
            iota(parent.begin(), parent.end(), 0);
            sort(cells.begin(), cells.end(),
                 [&](int a, int b) { return grid[a / n][a % n] < grid[b / n][b % n]; });
            sort(order.begin(), order.end(), [&](int a, int b) { return queries[a] < queries[b]; });
            auto find = [&](int a) {
                while (parent[a] != a) {
                    parent[a] = parent[parent[a]];
                    a = parent[a];
                }
                return a;
            };
            int at = 0;
            vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (int qi : order) {
                while (at < total && grid[cells[at] / n][cells[at] % n] < queries[qi]) {
                    int x = cells[at++];
                    active[x] = true;
                    for (auto [dr, dc] : dirs) {
                        int r = x / n + dr, c = x % n + dc;
                        if (r < 0 || r >= m || c < 0 || c >= n || !active[r * n + c]) continue;
                        int a = find(x), b = find(r * n + c);
                        if (a != b) {
                            if (size[a] < size[b]) swap(a, b);
                            parent[b] = a;
                            size[a] += size[b];
                        }
                    }
                }
                if (active[0]) answer[qi] = size[find(0)];
            }
            return answer;
        }
};
