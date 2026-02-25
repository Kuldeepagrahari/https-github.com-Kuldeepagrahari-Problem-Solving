class cmp {
public:
    bool operator()(int a, int b) {
        int seta = __builtin_popcount(a);
        int setb = __builtin_popcount(b);

        if(seta < setb) {
            return true;
        }
        else if(seta == setb) return a < b;
        return false;
    }

};
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp());
        return arr;
    }
};