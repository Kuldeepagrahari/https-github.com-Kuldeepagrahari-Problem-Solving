class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        int l = 0, r = 0;
        vector<int> ans;

        for(; r < n; r++) {
            // delete
            while(!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }

            // insert
            q.push_back(r);

            // update
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