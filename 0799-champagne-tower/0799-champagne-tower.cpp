class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur(100, 0.0);
        vector<double> nxt(100, 0.0);
        cur[0] = poured;
        
        for(int row = 0; row < 99; row++) {
            for(int col = 0; col <= row; col++) {
                int left_child = col;
                int right_child = col + 1;

                double avail = cur[col];

                if(avail > 1.0) {
                    double div = (avail - 1.0) / 2.0;
                    nxt[left_child] += div;
                    nxt[right_child] += div;
                    cur[col] = 1.0;
                }

                if(row == query_row && col == query_glass) return cur[col];
            }
            cur = nxt;
            nxt.assign(100, 0.0);
        }

        for(int col = 0; col < 100; col++) {
            cur[col] = cur[col] >= 1.0 ? 1.0 : cur[col];
            if(query_row == 99 && col == query_glass) return cur[col];
        }
        return 0.0;

    }
};