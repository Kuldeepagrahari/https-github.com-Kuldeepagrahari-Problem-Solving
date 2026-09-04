class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int mx = 0, mn = 1e9+2;

            //max
            for(int j = 0; j <= i; j++) {
                mx = max(mx, nums[j]);
            }
            //min
            for(int j = i; j < n; j++) {
                mn = min(mn, nums[j]);
            }

            int instability_score = mx - mn;

            if(instability_score <= k) {
                return i;
            }

        }

        return -1;
    }
};