class cmp {
public:
    bool operator()(const int& x, const int& y) {
        return abs(x) < abs(y);
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp());
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int x = nums[i];
            if(i < n / 2) {
                ans -= x * x;
            }
            else {
                ans += x * x;
            }
        }

        return ans;
    }
};