class Solution {
public:
    vector<int> computeLPS(string& b) {
        int m = b.size();
        vector<int> lps(m);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (b[i] == b[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    i++;
                }
            }
        }
        return lps;
    }
    int KMP(string& a, string& b) {
        int n = a.size();
        int m = b.size();
        vector<int> lps = computeLPS(b);

        int i = 0, j = 0;
        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;
            } else if (i < n && a[i] != b[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        int j = 0;
        for (int i = 0; i < m - 1; i++) {
            char ch = a[j];
            a += ch;
            j = (j + 1) % n;
        }
        int startIdx = KMP(a, b);
        int ans = -1;
        if (startIdx != -1) {
            int x = startIdx + m;
            ans = x / n;
            if (x % n)
                ans++;
        }
        return ans;
    }
};