class Solution {
    const int mod = 1e9 + 7;
public:
    int numSub(string s) {
        int n = s.length();
        long long ans = 0;
        long long cnt = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') cnt++;
            else {
                long long ss = cnt * (cnt + 1) / 2;
                ans = (ans + ss) % mod;
                cnt = 0;
            }
        }
        long long ss = cnt * (cnt + 1) / 2;
        ans = (ans + ss) % mod;

        return int(ans);
    }
};