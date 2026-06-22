class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> freq;

        for(char ch: text) {
            freq[ch]++;
        }

        int num = min(freq['a'], min(freq['b'], min(freq['l']/2, min(freq['o']/2, freq['n']))));

        return num;
    }
};