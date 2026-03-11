class Solution {
public:
    int bitwiseComplement(int n) {
        int complement = 0;

        if(n == 0)
            return 1;

        int i = 0;

        while(n) {
            int bit = n % 2;

            if(bit == 0) {
                complement += pow(2, i);
            }

            i++;

            n /= 2;
        }

        return complement;
    }
};