class Solution {
public:

    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size(), m = grid[0].size();
        
        vis[i][j] = 1;

        int dirx[4] = {-1, 0, 1, 0};
        int diry[4] = {0, -1, 0, 1};

        for(int k = 0; k < 4; k++) {
            int ni = i + dirx[k];
            int nj = j + diry[k];

            if(ni >= 0 && ni < n && nj >= 0 && nj < m) {

                if(!vis[ni][nj] && (grid[i][j] == grid[ni][nj])) {
                    if(dfs(ni, nj, i, j, grid, vis) == true) 
                        return true;
                }
                else if(vis[ni][nj] == 1 && (ni != pi || nj != pj) && grid[ni][nj] == grid[i][j])
                    return true;
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1, grid, vis) == true)
                        return true;
                }
            }
        }

        return false;

    }
};