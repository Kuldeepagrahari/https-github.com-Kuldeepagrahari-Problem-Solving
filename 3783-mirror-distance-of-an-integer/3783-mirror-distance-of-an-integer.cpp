class Solution {
public:
    int do_reverse(int n) {
        int l = log(n)/log(10) + 1;
        int revInd = l - 1;
        int rev = 0;

        while(n) {
            int dig = n % 10;
            int power = pow(10, revInd);
            int revDig = power * dig;
    
            rev += revDig;
            revInd--;
            n /= 10;
        }

        return rev;
    }
    int mirrorDistance(int n) {
        if(n == 1e9)
            return 1e9 - 1;
        int rev = do_reverse(n);
        int mirrorDistance = abs(n - rev);

        return mirrorDistance;
    }
};