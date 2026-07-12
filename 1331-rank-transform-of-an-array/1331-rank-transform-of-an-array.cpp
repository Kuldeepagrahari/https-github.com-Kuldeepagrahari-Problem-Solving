class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> mp(n);

        for(int i = 0; i < n; i++) {
            mp[i] = {arr[i], i};
        }

        sort(mp.begin(), mp.end());

        vector<int> rank_vec(n);
        int rank = 0;
        int prevVal = -1e9-1;

        for(int i = 0; i < n; i++) {
            auto [val, ind] = mp[i];
            if(val != prevVal) {
                rank++;
                prevVal = val;
            }
            rank_vec[mp[i].second] = rank;
        }

        return rank_vec;


    }
};