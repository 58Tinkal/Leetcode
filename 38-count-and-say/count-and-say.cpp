class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if (n == 1)
            return s;
        for (int i = 2; i <= n; i++) {
            int m = s.size();
            char c = s[m - 1];
            int cnt = 0;
            string str = "";
            for (int j = m - 1; j >= 0; j--) {
                if (c == s[j]) {
                    cnt++;
                } else {
                    str += c;
                    str += char(cnt + '0');
                    cnt = 1;
                    c = s[j];
                }
            }
            str += c;
            str += char(cnt + '0');
            reverse(str.begin(), str.end());
            s = str;
        }
        return s;
    }
};