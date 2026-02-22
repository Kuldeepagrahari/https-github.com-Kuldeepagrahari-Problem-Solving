class Solution {
public:
    int binaryGap(int n) {
        int cnt0 = 0;
        bool gotBit1 = false;
        int ans = 0;
        while(n > 0) {
            int bit = n % 2;

            if(bit == 0) {
                cnt0++;
            }
            else {
                if(gotBit1) {
                    int distance = cnt0 + 1;
                    ans = max(ans, distance);
                }
                gotBit1 = true;
                cnt0 = 0;
            }

            n /= 2;
        }

        return ans;
    }
};