class Solution {
public:
    bool isOneBitCharacter(vector<int>& s) {
        int n = s.size();
        if ( n == 1)return true;
        for ( int i = 0 ;i < n ; i ++ ){
            if(i == n-1 )return true;
            if ( s[i] == 0 && (i == 0 || (i > 0 && s[i-1] != 1)))continue;
            else if ( s[i] == 1){s[i+1] = -1; i++;}
        }
        return false;
    }
};