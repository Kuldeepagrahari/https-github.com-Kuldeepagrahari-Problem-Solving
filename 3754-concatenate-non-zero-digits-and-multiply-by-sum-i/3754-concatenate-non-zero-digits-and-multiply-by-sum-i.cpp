class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        vector<int> v;
        while(n) {
            int dig = n % 10;
            if(dig != 0) {
                v.push_back(dig);
            }
            n /= 10;
        }
        int sumDigit = 0;
        int m = v.size();
        for(int i = m - 1; i >= 0; i--) {
            x *= 10;
            x += v[i];
            sumDigit += v[i];
        }

        long long ans = x * 1LL * sumDigit;
        return ans;
    }
};