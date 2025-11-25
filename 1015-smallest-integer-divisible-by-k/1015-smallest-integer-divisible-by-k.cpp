class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1) return 1;

        if(k % 2 == 0 || k % 5 == 0) return -1;
        long long n = 1;
        int idx = 1;
        while(n % k != 0) {
            n = (n * 10 + 1) % k;
            idx++;
            if(n == 0) return idx;
        }

        return -1;
    }
};