class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<char>> vis(m, vector<char>(n, 'E'));
        for (auto it : guards) {
            vis[it[0]][it[1]] = 'G';
        }
        for (auto it : walls) {
            vis[it[0]][it[1]] = 'W';
        }
        for (int i = 0; i < m; i++) {
            bool seen = false;
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 'G') {
                    seen = true;
                }
                if (vis[i][j] == 'W') {
                    seen = false;
                }
                if (vis[i][j] == 'E' && seen) {
                    vis[i][j] = 'S';
                }
            }
            seen = false;
            for (int j = n - 1; j >= 0; j--) {
                if (vis[i][j] == 'G') {
                    seen = true;
                }
                if (vis[i][j] == 'W') {
                    seen = false;
                }
                if (vis[i][j] == 'E' && seen) {
                    vis[i][j] = 'S';
                }
            }
        }
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = 0; i < m; i++) {
                if (vis[i][j] == 'G')
                    seen = true;
                if (vis[i][j] == 'W')
                    seen = false;
                if (vis[i][j] == 'E' && seen)
                    vis[i][j] = 'S';
            }
            seen = false;
            for (int i = m - 1; i >= 0; i--) {
                if (vis[i][j] == 'G')
                    seen = true;
                if (vis[i][j] == 'W')
                    seen = false;
                if (vis[i][j] == 'E' && seen)
                    vis[i][j] = 'S';
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 'E')
                    ans++;
            }
        }
        return ans;
    }
};