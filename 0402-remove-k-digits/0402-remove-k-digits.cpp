class Solution {
public:
    string removeKdigits(string num, int k) {
        // Edge Cases
        // 1. n = k: "0"
        // 2. num[i] = '0', push if st is not empty
        int n = num.length();
        stack<char> st;
        st.push(num[0]);

        for(int i = 1; i < n; i++) {
            while(!st.empty() && k && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
            if(st.top() == '0' && st.size() == 1) st.pop();
        }

        while(k-- && !st.empty()) {
            st.pop();
        }

        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        if(ans.length() == 0) return "0";
        return ans;
    }
};