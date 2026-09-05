class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMax(n, 0);
        prefixMax[0] = nums[0];
        vector<int> suffixMin(n, 0);
        suffixMin[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        for(int i = 0; i < n; i++) {
            int mx = prefixMax[i];
            int mn = suffixMin[i];

            int instability_score = mx - mn;

            if(instability_score <= k) {
                return i;
            }
        }

        return -1;
    }
};