class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                int dist = i - prev - 1;
                if(!(prev == -1 || dist >= k)) return false;
                prev = i;
            }
        }
        return true;
    }
};