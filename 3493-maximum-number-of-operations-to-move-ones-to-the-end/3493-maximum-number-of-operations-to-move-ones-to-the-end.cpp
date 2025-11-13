class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int oprn = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0' && (i == n - 1 || s[i + 1] == '1')) {
                oprn += cnt;
            }
            if(s[i] == '1') cnt++;
        }

        return oprn;
    }
};