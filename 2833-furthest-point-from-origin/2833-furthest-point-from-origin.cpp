class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int Lcnt = 0, Rcnt = 0;
        for(int i = 0; i < n; i++) 
        {
            if(moves[i] == 'L')
                Lcnt++;
            else if(moves[i] == 'R')
                Rcnt++;
        }

        int Ucnt = n - Lcnt - Rcnt;

        int ans = abs(Lcnt - Rcnt) + Ucnt;
        return ans; 
    }
};