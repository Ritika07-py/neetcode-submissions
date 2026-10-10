class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visit;
        int x = 0, y = 0;
        visit.insert(to_string(x) + "," + to_string(y));

        for (char c : path) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else if (c == 'W') x--;

            string pos = to_string(x) + "," + to_string(y);
            if (visit.count(pos)) return true;
            visit.insert(pos);
        }

        return false;
    }
};