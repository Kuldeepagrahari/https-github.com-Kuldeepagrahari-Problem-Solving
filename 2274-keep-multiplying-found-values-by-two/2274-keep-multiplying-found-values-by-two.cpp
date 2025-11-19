class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st;
        for(int x : nums) st.insert(x);
        while(st.count(original)) {
            original *= 2;
        }

        return original;
    }
};