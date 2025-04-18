class Solution {
public:
    string fun(int n) {
        if (n == 1) {
            return "1";
        }
        string s = fun(n - 1);
        string str = "";
        int m = s.size();
        char c = s[m - 1];
        int cnt = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (c == s[i]) {
                cnt++;
            } else {
                str += c;
                str += char(cnt + '0');
                cnt = 1;
                c = s[i];
            }
        }
        str += c;
        str += char(cnt + '0');
        reverse(str.begin(), str.end());
        return str;
    }
    string countAndSay(int n) { return fun(n); }
};