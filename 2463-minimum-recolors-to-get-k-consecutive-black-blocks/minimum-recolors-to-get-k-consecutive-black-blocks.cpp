class Solution {
public:
    int minimumRecolors(string s, int k) {
        int c = 0, ans = 1e9;
        int n = s.size();
        for (int i = 0; i < k; i++) {
            if (s[i] == 'W')
                c++;
        }
        ans = c;
        for (int i = k; i < n; i++) {
            if (s[i - k] == 'W')
                c--;
            if (s[i] == 'W')
                c++;
            ans = min(ans, c);
        }
        return ans;
    }
};