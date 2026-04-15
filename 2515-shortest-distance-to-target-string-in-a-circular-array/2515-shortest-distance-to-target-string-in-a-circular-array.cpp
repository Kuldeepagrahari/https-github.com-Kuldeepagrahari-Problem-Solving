class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int mnDis = 1e9;

        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int dis = 1e9, revDis = 1e9;
                if(startIndex > i) {
                    dis = abs(startIndex - i);
                    revDis = i + n - startIndex;
                }
                else {
                    dis = abs(i - startIndex);
                    revDis = abs(startIndex + n - i);
                }
                mnDis = min({mnDis, dis, revDis});
            }
        }

        return mnDis == 1e9 ? -1 : mnDis;
    }
};