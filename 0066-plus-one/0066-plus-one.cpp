class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int carry = 1;
        for(int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            if(sum > 9) carry = 1;
            else carry = 0;
            int sumDig = sum % 10;
            ans.push_back(sumDig);
        }

        if(carry) ans.push_back(carry);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};