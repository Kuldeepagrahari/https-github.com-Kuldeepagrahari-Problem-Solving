class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int, int> mp;
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        int l = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(i >= k - 1) {
                for(auto [val, freq] : mp) {
                    pq.push({freq, val});
                }
                int xsum = 0;
                int j = 0;
                while(!pq.empty()) {
                    auto [freq, val] = pq.top();
                    pq.pop();
                    if(j < x) xsum += val * freq;
                    j++;
                }
                ans.push_back(xsum);
                mp[nums[l++]]--;
            }
       
        } 

        return ans;

    }
};