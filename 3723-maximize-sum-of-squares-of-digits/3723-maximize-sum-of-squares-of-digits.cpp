class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;

        while(sum > 0 && num > 0) {
            num--;
            if(sum > 9) {
                ans.push_back('9');
                sum -= 9;
            }
            else {
                ans.push_back(sum + '0');
                sum = 0;
                break;
            }
        }

        if(num == 0 && sum > 0) {
            return "";
        }

        while(num > 0) {
            ans.push_back('0');
            num--;
        }

        return ans;
    }
};