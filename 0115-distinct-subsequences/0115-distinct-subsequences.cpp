class Solution {
public:
    int solve(int sIdx, int tIdx, string &s, string &t, vector<vector<int>>& dp) {
        if(tIdx == t.length())
            return 1;
        if(sIdx == s.length())
            return 0;

        if(dp[sIdx][tIdx] != -1) {
            return dp[sIdx][tIdx];
        }

        int take = 0, notTake = 0;

        if(s[sIdx] == t[tIdx]) {
            take = solve(sIdx + 1, tIdx + 1, s, t, dp);
        }
        notTake = solve(sIdx + 1, tIdx, s, t, dp);

        return dp[sIdx][tIdx] = take + notTake;
    }
    int numDistinct(string s, string t) {

        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solve(0, 0, s, t, dp);
    }
       
};