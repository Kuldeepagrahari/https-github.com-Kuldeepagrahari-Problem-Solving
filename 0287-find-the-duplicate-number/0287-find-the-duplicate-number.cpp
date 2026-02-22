class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        // Approach 1 -> Using O(n) space
        // unordered_set<int> st;
        // for(int x: nums) {
        //     if(st.find(x) != st.end())
        //         return x;
        //     st.insert(x);
        // }

        // Approach 2 -> using O(nlogn) time complexity
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) 
                return nums[i];
        }

        return 0;
        
    }
};