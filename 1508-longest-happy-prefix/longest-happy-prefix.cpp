class Solution {
private:
    vector<int> computeLPS(string& s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0;
        for (int i = 1; i < n;) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps = computeLPS(s);
        string ans = "";
        if (lps[n - 1] == 0) {
            return ans;
        }
        for (int i = 0; i < lps[n - 1]; i++) {
            ans += s[i];
        }
        return ans;
    }
};