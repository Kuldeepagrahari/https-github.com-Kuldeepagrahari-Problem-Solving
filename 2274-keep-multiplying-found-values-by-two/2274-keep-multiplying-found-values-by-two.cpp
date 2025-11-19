class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st;
        for(int x : nums) st.insert(x);
        while(st.find(original) != st.end()) {
            original *= 2;
        }

        return original;
    }
};