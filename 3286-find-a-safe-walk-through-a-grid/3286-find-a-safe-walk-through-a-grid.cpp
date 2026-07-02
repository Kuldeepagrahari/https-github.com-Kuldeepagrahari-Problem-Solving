class cmp {
public:
    bool operator()(const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) {
        return p1.first < p2.first;
    }
};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> H(n, vector<int>(m, 0));

        H[0][0] = health - grid[0][0];
        pq.push({H[0][0], {0, 0}});
        vis[0][0] = 1;

        int dirx[4] = {-1, 0, 1, 0};
        int diry[4] = {0, -1, 0, 1};

        while(!pq.empty()) {
            auto [health, it] = pq.top();
            pq.pop();
            auto [row, col] = it;

            if(row == n - 1 && col == m - 1)
                return true;
            
            for(int k = 0; k < 4; k++) {
                int curRow = row + dirx[k];
                int curCol = col + diry[k];

                if(curRow >= 0 && curRow < n && curCol >= 0 && curCol < m && !vis[curRow][curCol]) {
                    int curHealth = health - grid[curRow][curCol];
                    if(curHealth > H[curRow][curCol]) {
                        pq.push({curHealth, {curRow, curCol}});
                        vis[curRow][curCol] = 1;
                        H[curRow][curCol] = curHealth;
                    }
                }
            }
        }

        return vis[n - 1][m - 1];
    }
};