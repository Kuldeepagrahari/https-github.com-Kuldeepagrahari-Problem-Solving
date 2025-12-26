class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        vector<int> NoCustomer(n + 1, 0);
        vector<int> Customer_ShopClosed(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            if(customers[i - 1] == 'N') {
                NoCustomer[i] = NoCustomer[i - 1] + 1;
            }
            else {
                NoCustomer[i] = NoCustomer[i - 1];
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            if(customers[i] == 'Y') {
                Customer_ShopClosed[i] = Customer_ShopClosed[i + 1] + 1;
            }
            else {
                Customer_ShopClosed[i] = Customer_ShopClosed[i + 1];
            }
        }

        int mnPenality = 1e9;
        int hr = 0;
        for(int i = 0; i <= n; i++) {
            int curPenality = NoCustomer[i] + Customer_ShopClosed[i];
            if(mnPenality > curPenality) {
                mnPenality = curPenality;
                hr = i;
            }
        }

        return hr;
    }
};