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
                int row = cr, col = i;
                elem.push_back(grid[row][col]);
            }

            // t -> b
            for(int i = cr + 1; i < n - cr; i++) {
                int row = i, col = m - cc - 1;
                elem.push_back(grid[row][col]);
            }

            // r -> l
            for(int i = m - cc - 2; i >= cc; i--) {
                int row = n - cr - 1, col = i;
                elem.push_back(grid[row][col]);
            }

            // b -> t
            for(int i = n - cr - 2; i >= cr + 1; i--) {
                int row = i, col = cc;
                elem.push_back(grid[row][col]);
            }

            int rot = k % (elem.size());
            rotate(elem.begin(), elem.begin() + rot, elem.end());

            int j = 0;
             // l -> r
            for(int i = cc; i < m - cc; i++) {
                int row = cr, col = i;
                grid[row][col] = elem[j++];
            }

            // t -> b
            for(int i = cr + 1; i < n - cr; i++) {
                int row = i, col = m - cc - 1;
                grid[row][col] = elem[j++];
            }

            // r -> l
            for(int i = m - cc - 2; i >= cc; i--) {
                int row = n - cr - 1, col = i;
                grid[row][col] = elem[j++];
            }

            // b -> t
            for(int i = n - cr - 2; i >= cr + 1; i--) {
                int row = i, col = cc;
                grid[row][col] = elem[j++];
            }

            cr++;
            cc++;

        }

        return grid;
    }
};