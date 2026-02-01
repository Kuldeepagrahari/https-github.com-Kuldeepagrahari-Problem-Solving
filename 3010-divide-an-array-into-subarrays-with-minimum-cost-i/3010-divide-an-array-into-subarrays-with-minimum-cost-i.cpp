class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int mn = 51;
        int sec_mn = 51;

        for(int i = 1; i < n; i++) {
            if(nums[i] <= mn) {
                sec_mn = mn;
                mn = nums[i];
            }
            else {
                sec_mn = min(sec_mn, nums[i]);
            }
        } 

        return nums[0] + mn + sec_mn;
    }
};