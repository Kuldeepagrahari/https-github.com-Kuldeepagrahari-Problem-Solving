class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int numOfPossibleSubstrings = pow(2, k);
        unordered_set<string> st;

        for(int i = 0; i <= n - k; i++) {
            string ss = "";
            for(int j = i; j < i + k; j++) {
                ss += s[j];
            }
            st.insert(ss);
        }

        for(string s: st) cout << s << endl;

        return st.size() == numOfPossibleSubstrings;

        
        

    }
};