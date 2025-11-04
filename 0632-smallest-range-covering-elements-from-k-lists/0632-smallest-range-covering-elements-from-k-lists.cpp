class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> idx(k, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn;
        int mx = -1e9;

        for(int i = 0; i < k; i++) {
            mn.push({nums[i][0], i});
            mx = max(mx, nums[i][0]);
        }
        int mnDif = mx - mn.top().first;
        vector<int> mnRange = {mn.top().first, mx};

        while(!mn.empty()) {
            auto [val, list] = mn.top();
            mn.pop();

            if(idx[list] + 1 < nums[list].size()) {
        
                idx[list] ++;
                int next = nums[list][idx[list]];
                mx = max(mx, next);
                mn.push({next, list});
            }
            else break;

            int a = mn.top().first;
            int b = mx;
            int dif = b - a;
            int c = mnRange[0];
            if(dif < mnDif || dif == mnDif && a < c) {
                mnDif = dif;
                mnRange = {a, b};
            }
           
            cout << a << " " << b << endl;
        }

        return mnRange;

    }
};