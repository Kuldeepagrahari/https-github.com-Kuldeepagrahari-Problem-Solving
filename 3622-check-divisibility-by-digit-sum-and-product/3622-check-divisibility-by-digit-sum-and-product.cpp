class Solution {
public:
    pair<int, int> utils(int n) {
        int sum = 0, prod = 1;
        while(n) {
            int dig = n % 10;
            sum += dig;
            prod *= dig;
            n /= 10;
        }
        return {sum, prod};
    }

    bool checkDivisibility(int n) {
        auto [digSum, digProd] = utils(n);

        int sum = digSum + digProd;

        return n % sum == 0;
    }
};