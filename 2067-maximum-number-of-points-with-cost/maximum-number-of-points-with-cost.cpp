class Solution {
public:

    long long maxPoints(vector<vector<int>>& p) {
        int n=p.size();
        int m=p[0].size();
        vector<long long>dp;
        for(int i=0;i<m;i++)dp.push_back(p[0][i]);
        for(int i=1;i<n;i++){
            vector<long long>dp2(m);
        long long mx=dp[0];
            for(int j=0;j<m;j++){
                 dp2[j]=max(mx,dp[j]);
                 mx=dp2[j]-1;
            }
            mx=dp[m-1];
              for(int j=m-1;j>=0;j--){
                 dp2[j]=max(dp2[j],max(mx,dp[j]));
                 mx=dp2[j]-1;
            }
            for(int j=0;j<m;j++){
                dp2[j]+=p[i][j];
            }
          dp=dp2;
        }
    long long mx=dp[0];
        for(int i=0;i<m;i++){
            mx=max(dp[i],mx);
        }
        return mx;
    }
};