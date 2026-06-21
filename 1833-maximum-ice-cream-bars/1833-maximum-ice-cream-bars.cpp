class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int bars = 0;
        sort(costs.begin(), costs.end());
        int i = 0;

        while(i < n && coins - costs[i] >= 0) {
            coins -= costs[i];
            bars++;
            i++;
        }

        return bars;
    }
};