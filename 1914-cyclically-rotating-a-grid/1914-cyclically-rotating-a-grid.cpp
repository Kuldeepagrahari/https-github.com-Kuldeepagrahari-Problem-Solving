class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int cr = 0, cc = 0;
        int layers = min(m, n) / 2;

        while(layers--) {
            vector<int> elem;

            // l -> r
            for(int i = cc; i < m - cc; i++) {
                elem.push_back(grid[cr][i]);
            }

            // t -> b
            for(int i = cr + 1; i < n - cr; i++) {
                elem.push_back(grid[i][m - cc - 1]);
            }

            // r -> l
            for(int i = m - cc - 2; i >= cc; i--) {
                elem.push_back(grid[n - cr - 1][i]);
            }

            // b -> t
            for(int i = n - cr - 2; i >= cr + 1; i--) {
                elem.push_back(grid[i][cc]);
            }

            int rot = k % (elem.size());
            rotate(elem.begin(), elem.begin() + rot, elem.end());
            int j = 0;
             // l -> r
            for(int i = cc; i < m - cc; i++) {
                grid[cr][i] = elem[j++];
            }

            // t -> b
            for(int i = cr + 1; i < n - cr; i++) {
                grid[i][m - cc - 1] = elem[j++];
            }

            // r -> l
            for(int i = m - cc - 2; i >= cc; i--) {
                grid[n - cr - 1][i] = elem[j++];
            }

            // b -> t
            for(int i = n - cr - 2; i >= cr + 1; i--) {
                grid[i][cc] = elem[j++];
            }

            cr++;
            cc++;

        }

        return grid;
    }
};