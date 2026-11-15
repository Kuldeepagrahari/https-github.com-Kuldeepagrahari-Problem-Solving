class Solution {
public:
    const int MOD = 1e9+7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int prefix_sum = 0;
        long int odd_cnt = 0, even_cnt = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            prefix_sum += arr[i];

            if(prefix_sum & 1) {
                ans++; // the complete prefix array is also a valid target
                ans = (ans + even_cnt) % MOD; // removing all the even sum prefixes will give valid targets
                odd_cnt++;
            }
            else {
                ans = (ans + odd_cnt) % MOD;
                even_cnt++;
            }
        }
        // sum k tar = ps - k   tar = 
        return ans;
    }
};

