class Solution {
    int n, m, w;
    int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, -1, 0, 1};
    vector<vector<bool>> vis;

    bool solve(vector<vector<char>>& board, string& word, int row, int col, int ind) {
        if(ind >= w) return true;
        if(row >= n && col >= m) return false;
        
        bool found = false;
        for(int d = 0; d < 4; d++) {
            int nrow = row + dirx[d];
            int ncol = col + diry[d];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[ind]) {
                vis[nrow][ncol] = true;
                found |= solve(board, word, nrow, ncol, ind + 1);
                vis[nrow][ncol] = false;
            }
        }
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        w = word.size();
        vis.resize(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    vis[i][j]=true;
                    if(solve(board, word, i, j, 1)) return true;
                    vis[i][j]=false;
                }
            }
        }

        return false;
    }
};