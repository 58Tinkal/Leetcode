class Solution {
public:
// i=p,j=s;
    bool f(int i,int j,int n,int m,string &p,string &s,vector<vector<int>>&dp){
         if(i==n&&j==m)  return true;
         else if(i==n&&j<m)  return false;
        else if(i<n&&j==m){
            for(int ii=i;ii<n;ii++){
                if(p[ii]!='*')  return false;
            }
            return true;
        }
      if(dp[i][j]!=-1)  return dp[i][j];
       if(s[j]==p[i]||p[i]=='?'){
        return dp[i][j]=f(i+1,j+1,n,m,p,s,dp);
       }
       else if(p[i]=='*'){
        return dp[i][j]=f(i,j+1,n,m,p,s,dp)||f(i+1,j,n,m,p,s,dp);
       }
       // when not mached
        return dp[i][j]=false; 
    }
    bool isMatch(string s, string p) {
       int n=p.size();
       int m=s.size(); 
       vector<vector<int>>dp(n,vector<int>(m,-1));
       //p,s;
       return f(0,0,n,m,p,s,dp);
    }
};