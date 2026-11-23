class ProductOfNumbers {
public:
    int last0 = -1;
    int prod = 1;
    vector<int> v;
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            last0 = v.size();
            prod = 1;
            v.push_back(0);
        } else {
            prod *= num;
            v.push_back(prod);
        }
    }

    int getProduct(int k) {
        int n = v.size();
    
        if ( last0 >= 0 && last0 > n - k - 1 ) return 0;
        else {
            if ( n - k - 1 == -1 )return v[n - 1];
            else if ( v[n - k - 1] ==  0 ) return v[n - 1];
            return v[n - 1] / v[n - k - 1];
        }
     
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */