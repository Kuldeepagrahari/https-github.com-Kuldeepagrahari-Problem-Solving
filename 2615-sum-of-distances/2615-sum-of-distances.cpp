class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        // 5 0 2-0 + 3-2

        // 0 1 2 5 4    4-2 + 5-2*2 = dif(r, l) + i * (#l - #r)
        // 5 1 5 3 4

        // 5 0 3 4 0
        // 3-0 3-
        vector<pair<long long, long long>> L(n);
        map<int, pair<long long, long long>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].first += i;
            mp[nums[i]].second ++;
            L[i] = {mp[nums[i]].first, mp[nums[i]].second};
        }
        vector<pair<long long, long>> R(n);
        map<int, pair<long long, long long>> mp2;
        for(int i = n - 1; i >= 0; i--) {
            mp2[nums[i]].first += i;
            mp2[nums[i]].second ++;
            R[i] = {mp2[nums[i]].first, mp2[nums[i]].second};
        }

        for(int i = 0; i < n; i++) {
            long long sum = (R[i].first - L[i].first) + i * (L[i].second - R[i].second);
            ans[i] = sum;
        }

        return ans;
    }
};