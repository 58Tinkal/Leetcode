class Solution {
public:
 vector<int> col, ld, rd;
    vector<string> ds;
    int ans = 0;
      void solve(int r, int n) {
        if (r == n) {
           ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (col[i] == 0 && ld[r - i + n - 1] == 0 && rd[r + i] == 0) {
                ds[r][i] = 'Q';
                col[i] = ld[r - i + n - 1] = rd[r + i] = 1;
                solve(r + 1, n);
                ds[r][i] = '.';
                col[i] = ld[r - i + n - 1] = rd[r + i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
         ds = vector<string>(n, string(n, '.'));
        col = vector<int>(n, 0);
        ld = vector<int>(2 * n - 1, 0);
        rd = vector<int>(2 * n - 1, 0);
        solve(0, n);
        return ans;
    }
};