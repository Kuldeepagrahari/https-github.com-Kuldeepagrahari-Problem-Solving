class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            int rowPrefixSum = 0;
            for(int j = 0; j < m; j++) {
                rowPrefixSum += grid[i][j];
                grid[i][j] = (i - 1 >= 0 ? grid[i - 1][j] : 0) + rowPrefixSum;
                if(grid[i][j] <= k)
                    cnt += 1;
            }
        }

        return cnt;

    
    }
};