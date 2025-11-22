class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int oprn = 0;

        for(int x : nums) {
            int mod = x % 3;
            if(mod != 0) oprn ++;
        }

        return oprn;
    }
};