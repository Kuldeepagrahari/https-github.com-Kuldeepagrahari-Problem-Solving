class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // Step1: use result array from L->R for arr1 and R -> L for arr2
        // because we dont know the size of the arr1 and arr2
        result[0] = nums[0];
        result[n - 1] = nums[1];
        int idx1 = 1, idx2 = n - 2;
        int lastIdx1 = 0, lastIdx2 = 1;

        for(int idx = 2; idx < n; idx++) {
            if(nums[lastIdx1] > nums[lastIdx2]) {
                lastIdx1 = idx;
                result[idx1++] = nums[lastIdx1];
            }
            else {
                lastIdx2 = idx;
                result[idx2--] = nums[lastIdx2];
            }
        }

        // Step2: reverse arr2 
        idx2++;
        int revIdx2 = n - 1;
        while(idx2 < revIdx2)
            swap(result[idx2++], result[revIdx2--]);

        return result;
    }
};