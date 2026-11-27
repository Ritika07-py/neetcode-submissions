class Solution {
public:
    unordered_set<int> secrets, visit;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        secrets = {0, firstPerson};
        unordered_map<int, unordered_map<int, vector<int>>> time_map;

        for (auto& meet : meetings) {
            int src = meet[0], dst = meet[1], t = meet[2];
            time_map[t][src].push_back(dst);
            time_map[t][dst].push_back(src);
        }

        vector<int> timeKeys;
        for (auto& [t, _] : time_map) {
            timeKeys.push_back(t);
        }
        sort(timeKeys.begin(), timeKeys.end());

        for (int& t : timeKeys) {
            visit.clear();
            for (auto& [src, _] : time_map[t]) {
                if (secrets.count(src)) {
                    dfs(src, time_map[t]);
                }
            }
        }

        return vector<int>(secrets.begin(), secrets.end());
    }

private:
    void dfs(int src, unordered_map<int, vector<int>>& adj) {
        if (!visit.insert(src).second) return;
        secrets.insert(src);
        for (int& nei : adj[src]) {
            dfs(nei, adj);
        }
    }
};