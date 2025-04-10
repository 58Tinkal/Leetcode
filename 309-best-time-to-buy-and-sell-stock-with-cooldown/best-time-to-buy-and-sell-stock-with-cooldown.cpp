class Solution {
    int memoziation(vector<int>& prices, int i, int buy,vector<vector<int>>&dp) {
        if(i<0)  return 0;
        if (i == 0) {
            if (buy)
                return dp[0][buy]=-prices[0];
            else
                return 0;
        }
        if(dp[i][buy]!=-1)   return dp[i][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + memoziation(prices, i - 2, 0,dp),
                         memoziation(prices, i - 1, 1,dp));
        } else {
            profit = max(prices[i] + memoziation(prices, i - 1, 1,dp),
                         memoziation(prices, i - 1, 0,dp));
        }
        return dp[i][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return memoziation(prices,n-1,0,dp);
    }
};