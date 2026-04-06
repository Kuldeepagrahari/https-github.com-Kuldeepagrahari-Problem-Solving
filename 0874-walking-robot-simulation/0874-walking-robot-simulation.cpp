class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> blocked;
        
        for (auto &obs : obstacles) {
            blocked.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        vector<vector<int>> dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        int dir = 0; 
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } 
            else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } 
            else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dirs[dir][0];
                    int ny = y + dirs[dir][1];

                    if (blocked.count(to_string(nx) + "," + to_string(ny))) {
                        break; 
                    }

                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};