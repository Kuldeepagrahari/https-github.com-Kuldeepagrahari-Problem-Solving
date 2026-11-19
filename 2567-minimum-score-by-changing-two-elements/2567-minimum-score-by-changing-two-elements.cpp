class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return min(min({abs(nums[1] - nums[n - 1]), abs(nums[2] - nums[n - 1]), abs(nums[0] - nums[n - 2])}), min(abs(nums[0] - nums[n - 3]), abs(nums[1] - nums[n - 2])));
    }
};