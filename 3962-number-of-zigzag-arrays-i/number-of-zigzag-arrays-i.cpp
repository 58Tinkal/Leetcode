class Solution {
public:
    int dp[2000][2001][2];
    int p[2000][2001][2];
    int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        for(int i=0;i<n;++i){
            for(int j=l;j<=r;++j){
                for(int k=0;k<2;++k){
                    dp[i][j][k] = 0;
                    p[i][j][k] = 0;
                }
            }
        }
        for(int i=l;i<=r;++i){
            dp[0][i][0] = 1;
            dp[0][i][1] = 1;
        }
        for(int i=l;i<=r;++i){
            p[0][i][0] = ((i>0 ? p[0][i-1][0] : 0) + dp[0][i][0])%mod;
            p[0][i][1] = ((i>0 ? p[0][i-1][1] : 0) + dp[0][i][1])%mod;
        }
        for(int i=1;i<n;++i){
            int tot = p[i-1][r][1];
            for(int j=l;j<=r;++j){
                dp[i][j][1] = (dp[i][j][1] + (j>0 ? p[i-1][j-1][0]  : 0))%mod;
                dp[i][j][0] = (dp[i][j][0] + (tot - p[i-1][j][1] + mod)%mod)%mod;
                (p[i][j][0] = (j>0 ? p[i][j-1][0] : 0) + dp[i][j][0])%=mod;
                (p[i][j][1] = (j>0 ? p[i][j-1][1] : 0) + dp[i][j][1])%=mod;
            }
        }
        int ans = 0;
        for(int i=l;i<=r;++i){
            for(int j=0;j<2;++j)
                (ans+=dp[n-1][i][j])%=mod;
        }
        return ans;
    }
};
