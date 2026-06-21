class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int bars = 0;

        // Type1 Sorting Algo: In built Sorting -> O(NlogN)
        // sort(costs.begin(), costs.end());

        // Type2 sorting Algo: Count 
        int maxElem = 0;
        for(int i = 0; i < n; i++) {
            if(costs[i] > maxElem) {
                maxElem = costs[i];
            }
        }
        vector<int> freq(maxElem + 1, 0);
        for(int i = 0; i < n; i++) {
            freq[costs[i]]++;
        }

        for(int c = 1; c <= maxElem; c++) {
            if(freq[c] > 0) {
                while(freq[c]-- && coins - c >= 0) {
                    coins -= c;
                    bars++;
                }
            }
        }

        return bars;
    }
};