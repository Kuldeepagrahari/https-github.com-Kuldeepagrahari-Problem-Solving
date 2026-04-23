class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        //  dif(r, l) + i * (#l - #r)
        vector<pair<long long, long long>> L(n);
        unordered_map<int, pair<long long, long long>> mp;
        vector<pair<long long, long>> R(n);
        unordered_map<int, pair<long long, long long>> mp2;


        for(int i = 0; i < n; i++) {
            mp[nums[i]].first += i;
            mp[nums[i]].second ++;
            L[i] = {mp[nums[i]].first, mp[nums[i]].second};

            int j = n - i - 1;
            mp2[nums[j]].first += j;
            mp2[nums[j]].second ++;
            R[j] = {mp2[nums[j]].first, mp2[nums[j]].second};
        }

        for(int i = 0; i < n; i++) {
            long long sum = (R[i].first - L[i].first) + i * (L[i].second - R[i].second);
            ans[i] = sum;
        }

        return ans;
    }
};