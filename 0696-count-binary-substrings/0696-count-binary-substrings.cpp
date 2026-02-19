class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int pcnt = 1, ccnt = 0;
        int ans = 0;
        int i = 1;
        for(; i < n; i++) {
            if(s[i] != s[i - 1]) {
                break;
            }
            pcnt++;
        }
        if(i < n) ccnt = 1;
        for(; i < n - 1; i++) {
            if(s[i] == s[i + 1]) ccnt++;
            else
            {
                ans += min(pcnt, ccnt);
                pcnt = ccnt;
                ccnt = 1;
            }
        }

        ans += min(pcnt, ccnt);

        return ans;
    }
};