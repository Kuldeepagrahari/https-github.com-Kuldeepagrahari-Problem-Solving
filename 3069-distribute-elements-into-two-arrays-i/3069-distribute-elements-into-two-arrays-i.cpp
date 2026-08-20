class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        result[0] = nums[0];
        result[n - 1] = nums[1];
        int j1 = 1, j2 = n - 2;
        int i1 = 0, i2 = 1;

        for(int idx = 2; idx < n; idx++) {
            if(nums[i1] > nums[i2]) {
                i1 = idx;
                result[j1++] = nums[i1];
            }
            else {
                i2 = idx;
                result[j2--] = nums[i2];
            }
        }

        // reverse arr2
        j2++;
        int rev2 = n - 1;
        int n2 = n - j2;
        for(int idx = 0; idx < n2/2; idx++) {
            swap(result[j2++], result[rev2--]);
        }


        return result;
    }
};