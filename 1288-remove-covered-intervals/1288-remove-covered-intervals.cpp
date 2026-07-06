class cmp {
public:
    bool operator()(const vector<int>& I1, vector<int>& I2) {
        if(I1[0] < I2[0]) {
            return true;
        }
        else if(I1[0] == I2[0]) {
            return I1[1] > I2[1];
        }
        return false;
    }
};

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp());

        int mxRange = 0;
        int remSize = 0;
        for(int i = 0; i < n; i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(r > mxRange) {
                mxRange = r;
                remSize++;
            }
        }

        return remSize;
    }
};