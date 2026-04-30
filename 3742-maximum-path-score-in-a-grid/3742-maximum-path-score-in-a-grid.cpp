class Solution {
public:
    int solve(int row, int col, int cost, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size(), m = grid[0].size();
        
        // 1. Out of bounds check
        if (row >= n || col >= m) return -1e9; 

        // 2. Update current cost: if current cell is 1, increment cost
        int current_cost = (grid[row][col] == 0) ? cost : cost + 1;

        // 3. Pruning: If cost exceeds k, this path is dead
        if (current_cost > k) return -1e9;

        // 4. Base Case: Reached the bottom-right
        if (row == n - 1 && col == m - 1) {
            return grid[row][col];
        }

        // 5. Memoization check
        if (dp[row][col][current_cost] != -1) 
            return dp[row][col][current_cost];

        // 6. Recursive calls
        int right_score = solve(row, col + 1, current_cost, k, grid, dp);
        int down_score = solve(row + 1, col, current_cost, k, grid, dp);

        // 7. Calculate result: current cell value + max of paths
        int res = grid[row][col] + max(right_score, down_score);
        
        return dp[row][col][current_cost] = res;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        // Initialize DP with -1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        
        int ans = solve(0, 0, 0, k, grid, dp);
        
        // If the result is a very small number, no valid path was found
        return (ans < 0) ? -1 : ans;
    }
};