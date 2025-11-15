class StockSpanner {
    stack<int> st;
    vector<int> v;
    int idx = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && v[st.top()] <= price) {
            st.pop();
        }
        int pg = -1;
        if(!st.empty()) {
            pg = st.top();
        }
        st.push(idx);
        v.push_back(price);
        idx++;
        return idx - pg - 1;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */