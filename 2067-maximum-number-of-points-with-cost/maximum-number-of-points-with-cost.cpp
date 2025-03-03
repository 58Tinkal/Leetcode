#define ll long long int
class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int n = p.size();
        int m = p[0].size();
        vector<ll> dp(p[0].begin(), p[0].end());
        
        for (int i = 1; i < n; i++) {
            vector<ll> temp(m);

            // Left to right traversal
            ll mx = dp[0];
            for (int j = 0; j < m; j++) {
                mx = max(mx, dp[j]);
                temp[j] = mx;
                mx--;  
            }

            // Right to left traversal
            mx = dp[m - 1];
            for (int j = m - 1; j >= 0; j--) {
                mx = max(mx, dp[j]);  
                temp[j] = max(temp[j], mx); 
                mx--;  
            }

            // Update dp with the current row values
            for (int j = 0; j < m; j++) {
                dp[j] = temp[j] + p[i][j];
            }
        }

  
        return *max_element(dp.begin(), dp.end());
    }
};
