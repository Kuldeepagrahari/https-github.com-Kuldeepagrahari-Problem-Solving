class MedianFinder {
    priority_queue<int> mx; // max-heap = left elements
    priority_queue<int, vector<int>, greater<int>> mn; // min-heap = right elements
    int size = 0;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty()) {
            mx.push(num);
        }
        else
        {
            if(mx.top() >= num) {
                mx.push(num);
            }
            else {
                mn.push(num);
            }

            if(mx.size() > 1 + mn.size()) {
                int val = mx.top();
                mx.pop();
                mn.push(val);
                //  cout << "val" << val << endl;
            }
            if(mn.size() > mx.size()) {
                int val = mn.top();
                mn.pop();
                // cout << "val" << val << endl;
                mx.push(val);
            }
        }
        size++;
    }
    
    double findMedian() {
        if(size & 1) {
            return double(mx.top());
        }
        else {
            return (double(mx.top()) + double(mn.top())) / 2;
        }
    }
};

