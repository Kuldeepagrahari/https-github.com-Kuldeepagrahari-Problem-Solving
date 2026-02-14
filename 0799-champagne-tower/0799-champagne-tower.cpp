class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100, vector<double>(100, 0.0));
        dp[0][0] = double(poured);
        
        for(int row = 0; row < 99; row++) {
            for(int col = 0; col <= row; col++) {
                vector<int> left_child = {row + 1, col};
                vector<int> right_child = {row + 1, col + 1};

                double avail = dp[row][col];

                if(avail > 1.0) {
                    double div = (avail - 1.0) / 2.0;
                    dp[left_child[0]][left_child[1]] += div;
                    dp[right_child[0]][right_child[1]] += div;
                    dp[row][col] = 1.0;
                }
            }
        }

        for(int col = 0; col < 100; col++) {
            dp[99][col] = dp[99][col] >= 1.0 ? 1.0 : dp[99][col];
        }
        return dp[query_row][query_glass];

    }
};