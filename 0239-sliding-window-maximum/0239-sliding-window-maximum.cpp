class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        int l = 0, r = 0;
        vector<int> ans;

        for(; r < n; r++) {
            while(!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }

            q.push_back(r);
            if(r >= k - 1) {
                int mx = nums[q.front()];
                ans.push_back(mx);

                while(!q.empty() && q.front() <= l) {
                    q.pop_front();
                }
                l++;
            }
        }

        return ans;

    }
};