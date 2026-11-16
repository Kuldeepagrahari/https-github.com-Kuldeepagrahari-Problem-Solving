class Solution {
public:
    string digitSum(string s, int k) {

        while(s.length() > k) {
            string str = "";
            int sum = 0;
            int cnt = 0;

            for(int i = 0; i < s.length(); i++) {
                if(cnt == k) {
                    str += (to_string(sum));
                    sum = 0;
                    cnt = 0;
                }
                sum += (s[i] - '0');
                cnt++;
            }
            str += (to_string(sum));
            s = str;
            str = "";
        }

        return s;
    }
};