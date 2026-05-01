class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int sum = 0;
        for(int &x: nums)
            sum += x;
        
        int F = 0;
        for(int i = 0; i < n; i++) {
            F += i * nums[i];
        }

        ans = F;
        
        int rot_ind = n - 1;

        while(rot_ind >= 0) {
            int rot_key = nums[rot_ind];
            int reduction = (n - 1) * rot_key;
            int addition =  (sum - rot_key);
            F += (addition - reduction);
            rot_ind--;
            ans = max(ans, F);
        }

        return ans;
    }
};