class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int subMatrices = 0;

        vector<vector<pair<int, int>>> preCnt(n, vector<pair<int, int>>(m));


        for(int i = 0; i < n; i++) {
            int rowXCnt = 0;
            int rowYCnt = 0;

            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') {
                    rowXCnt ++;
                }
                else if(grid[i][j] == 'Y') {
                    rowYCnt++;
                }

                int xCnt = (i >= 1 ? preCnt[i - 1][j].first : 0) + rowXCnt;
                int yCnt = (i >= 1 ? preCnt[i - 1][j].second : 0) + rowYCnt;
                preCnt[i][j] = {xCnt, yCnt};

                if(xCnt == yCnt && xCnt > 0) {
                    subMatrices++;
                }
            }
        }

        return subMatrices;
    }
};