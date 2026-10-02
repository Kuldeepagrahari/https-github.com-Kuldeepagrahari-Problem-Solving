class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 0, close = 0;

        function<void(int, int, string)> f = [&](int open, int close, string s) -> void {
            if(open == n && close == n) {
                ans.push_back(s);
                return;
            }

            if(open == n) {
                s.push_back(')');
                f(open, close + 1, s);
                s.pop_back();
            }
            else if(open > close) {
                s.push_back('(');
                f(open + 1, close, s);
                s.pop_back();
                s.push_back(')');
                f(open, close + 1, s);
                s.pop_back();
            }
            else {
                s.push_back('(');
                f(open + 1, close, s);
                s.pop_back();
            }

        };
        f(0, 0, "");
        
        return ans;
    }
};