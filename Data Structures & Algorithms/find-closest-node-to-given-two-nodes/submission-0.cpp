class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) adj[i].push_back(edges[i]);
        }

        vector<int> node1Dist = bfs(node1, n, adj);
        vector<int> node2Dist = bfs(node2, n, adj);

        int res = -1, resDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (node1Dist[i] != -1 && node2Dist[i] != -1) {
                int dist = max(node1Dist[i], node2Dist[i]);
                if (dist < resDist) {
                    resDist = dist;
                    res = i;
                }
            }
        }
        return res;
    }

private:
    vector<int> bfs(int src, int n, vector<vector<int>>& adj) {
        vector<int> distMap(n, -1);
        queue<pair<int, int>> q;
        q.push({src, 0});
        distMap[src] = 0;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (distMap[nei] == -1) {
                    q.push({nei, dist + 1});
                    distMap[nei] = dist + 1;
                }
            }
        }
        return distMap;
    }
};