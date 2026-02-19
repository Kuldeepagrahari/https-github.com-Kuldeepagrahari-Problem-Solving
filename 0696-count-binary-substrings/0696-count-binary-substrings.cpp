class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int pcnt = 1, ccnt = 0;
        int ans = 0;
        int i = 0;

        for(; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                pcnt++;
            }
            else 
            {
                break;
            }
        }

        if(i < n - 1) {
            ccnt = 1;
            i++;
        }
        cout << i << " " << pcnt << endl;

        for(; i < n - 1; i++) {
            if(s[i] == s[i + 1]) ccnt++;
            else
            {
                ans += min(pcnt, ccnt);
                pcnt = ccnt;
                ccnt = 1;
            }
            cout << i << " "  << pcnt << endl;
        }

        ans += min(pcnt, ccnt);

        return ans;
    }
};