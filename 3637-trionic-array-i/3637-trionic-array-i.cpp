class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3)
            return false;
        
        bool isinc = true;
        int dec = 0, inc = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i - 1] > nums[i]) // dec
            {
                if(isinc) {
                    dec++;
                    isinc = false;
                }
            }
            else if(nums[i - 1] < nums[i]) // inc
            {
                if(!isinc) {
                    inc++;
                    isinc = true;
                }
                else
                {
                    if(inc == 0)
                        inc = 1;
                }
            }
            else
                return false;
            
        }
        if(inc == 2 && dec == 1) 
            return true;
        return false;
    }
};