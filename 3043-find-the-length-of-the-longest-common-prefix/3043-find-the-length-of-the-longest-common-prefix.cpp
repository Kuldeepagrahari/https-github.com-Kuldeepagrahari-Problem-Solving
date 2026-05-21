class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(int x: arr2) {
            int pref = 0;
            stack<int> sc;
            while(x) {
                int dig = x % 10;
                sc.push(dig);
                x /= 10;
            }

            while(!sc.empty()) {
                pref += sc.top();
                sc.pop();
                st.insert(pref);
                pref *= 10;
            }
        }

        int ans = 0;

        for(int x: arr1) {
            int pref = 0;
            stack<int> sc;
            while(x) {
                int dig = x % 10;
                sc.push(dig);
                x /= 10;
            }

            while(!sc.empty()) {
                pref += sc.top();
                sc.pop();
                if(st.find(pref) != st.end()) {
                    int len = log(pref) / log(10) + 1;
                    ans = max(ans, len);
                }
                pref *= 10;
            }
        }

        return ans;
    }
};