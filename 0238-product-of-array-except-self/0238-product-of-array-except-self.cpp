class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int zero = 0;
        vector<int> ans(n);

        for(int &x: nums) {
            if(x != 0) {
                prod *= x;
            }
            else {
                zero++;
            }
        }

        for(int i = 0 ; i < n; i++) {
            int x = nums[i];
            if(zero == 0) {
                ans[i] = prod / x;
            }
            else if(zero == 1 && x == 0) {
                ans[i] = prod;
            }
            else {
                ans[i] = 0;
            }
        }

        return ans;
    }
};