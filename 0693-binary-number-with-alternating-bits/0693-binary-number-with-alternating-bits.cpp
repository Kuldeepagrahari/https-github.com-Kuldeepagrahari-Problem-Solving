class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = n % 2, curBit;
        n /= 2;
        while(n > 0) {
            curBit = n % 2;
            n /= 2;
            if(curBit == prevBit) return false;
            prevBit = curBit;
        }

        return true;
    }
};