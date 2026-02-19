class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int pcnt = 0, ccnt = 1;
        int ans = 0;
        int i = 0;

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