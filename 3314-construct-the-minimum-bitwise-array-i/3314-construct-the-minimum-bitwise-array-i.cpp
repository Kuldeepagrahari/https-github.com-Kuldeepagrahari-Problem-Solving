class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int x = nums[i];
            bool found = false;
            for(int j = 0; j <= x; j++) {
                if((j | (j + 1)) == x) {
                    ans[i] = j;
                    found = true;
                    break;
                }
            }

            if(found == false) {
                ans[i] = -1;
            }
        }

        return ans;
    }
};