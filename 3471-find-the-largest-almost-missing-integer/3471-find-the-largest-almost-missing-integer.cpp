class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> hsh(51, 0);

        for(int i = 0; i < n - k + 1; i++) {
            vector<int> hsh2(51, 0);
            for(int j = i; j < i + k; j++) {
                hsh2[nums[j]]++;
            }

            for(int j = 0; j < 51; j++) {
                if(hsh2[j] > 0) {
                    hsh[j]++;
                }
            }
        }

        int ans = -1;
        for(int i = 0; i < 51; i++) {
            if(hsh[i] == 1) {
                ans = max(ans, i);
            }
        }

        return ans;
    }
};