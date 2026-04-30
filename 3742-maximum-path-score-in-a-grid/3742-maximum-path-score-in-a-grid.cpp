class Solution {
public:
    int solve(int row, int col, int cost, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        
        int loc_cost =  (grid[row][col] == 0 ? cost : cost + 1);
        int n = grid.size(), m = grid[0].size();

        if(loc_cost > k)
            return -1e9;

        if(row == n - 1 && col == m - 1) {
            return grid[n - 1][m - 1];
        }

        if(dp[row][col][loc_cost] != -1) 
            return dp[row][col][loc_cost];
        
        int right_score = -1e9, down_score = -1e9;

        // go to right
        if(col + 1 < m)
            right_score = grid[row][col] + solve(row, col + 1, loc_cost, k, grid, dp);
            
        if(row + 1 < n)
            down_score = grid[row][col] + solve(row + 1, col, loc_cost, k, grid, dp);
    

        return dp[row][col][loc_cost] = max(right_score, down_score);

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

        int ans = solve(0, 0, 0, k, grid, dp);

        if(ans < 0)
            return -1;

        return ans;
    }
};