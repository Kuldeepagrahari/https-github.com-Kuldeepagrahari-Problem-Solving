class Solution {
public:
    const int MOD = 1e9+7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int prefix_sum = 0;
        int odd_cnt = 0, even_cnt = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            prefix_sum += arr[i];

            if(prefix_sum & 1) {
                ans++; // the complete prefix array is also an odd sum subarray
                ans = (ans + even_cnt) % MOD; // removing all the even sum prefixes will give odd subarrays
                odd_cnt++;
            }
            else {
                ans = (ans + odd_cnt) % MOD; // removing all the odd sum prefixes will give even subarrays
                even_cnt++;
            }
        }

        return ans;
    }
};

