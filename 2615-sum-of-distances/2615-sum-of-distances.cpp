class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        for(auto &it : mp){
            auto &pos = it.second;

            long long sum = 0;
            for(int x : pos) sum += x;

            long long leftSum = 0;
            int m = pos.size(); // total cnt of occ of it.first

            for(int i = 0; i < m; i++){
                long long rightSum = sum - leftSum - pos[i];
                int cntl = i;
                int cntr = m - i - 1;
                int index = pos[i];

                ans[pos[i]] = (rightSum - leftSum) + index* 1LL * (cntl - cntr);

                leftSum += pos[i];
            }
        }

        return ans;
    }
};