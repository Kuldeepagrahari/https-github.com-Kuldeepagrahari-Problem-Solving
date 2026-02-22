class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        // Approach 1
        unordered_set<int> st;
        for(int x: nums) {
            if(st.find(x) != st.end())
                return x;
            st.insert(x);
        }

        return 0;
        
    }
};