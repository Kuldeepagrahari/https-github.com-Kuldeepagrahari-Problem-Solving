class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(int x: arr2) {
            while(x) {
                st.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        for(int x: arr1) {
            int len = log(x) / log(10) + 1;
            while(x) {
                if(st.find(x) != st.end()) {
                    ans = max(ans, len);
                    break;
                }
                x /= 10;
                len--;
            }
        }

        return ans;
    }
};