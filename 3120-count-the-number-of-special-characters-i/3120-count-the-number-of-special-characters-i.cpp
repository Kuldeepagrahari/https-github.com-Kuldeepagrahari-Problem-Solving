class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;

        for(char ch: word) {
            mp[ch]++;
        }
        int special = 0;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(mp[ch] > 0 && mp[ch - 32] > 0)
                special++;
        }

        return special;
    }
};