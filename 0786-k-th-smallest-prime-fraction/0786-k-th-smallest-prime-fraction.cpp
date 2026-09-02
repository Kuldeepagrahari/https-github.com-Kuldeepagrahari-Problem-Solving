class cmp {
public:
    bool operator()(const pair<double, vector<int>> &p1, const pair<double, vector<int>> &p2) {
        return p1.first < p2.first;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, cmp> pq;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int x = arr[i], y = arr[j];
                double div = double(x) / double(y);

                pq.push({div, {x, y}});

                if(pq.size() > k) {
                    pq.pop();
                }

            }
        }

        return pq.top().second;
        // return pq.top().second;

    }
};