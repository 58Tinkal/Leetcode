class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> pre(n, 0);
        pre[0] = (s[0] == '1') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0')
                pre[i] = pre[i - 1];
            if (s[i] == '1')
                pre[i] = pre[i - 1] + 1;
        }
        bool f = false;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0' && f == false) {
                ans += pre[i];
                f = true;
            }
            if (s[i] == '1') {
                f = false;
            }
        }
        return ans;
    }
};