class Solution {
public:
     vector<vector<int>>dp;
     int n;
     int solve(int i,int j,vector<int>&nums){
            if(i == n-1)  return max(nums[i],nums[j]);
            if(i==n) return nums[j];
            if(dp[i][j] != -1)  return dp[i][j];
            int ans = 1e9;
            ans = min(ans,max(nums[i],nums[i+1])+solve(i+2,j,nums));
            ans = min(ans,max(nums[j],nums[i+1])+solve(i+2,i,nums));
            ans = min(ans,max(nums[j],nums[i])+solve(i+2,i+1,nums));
            return dp[i][j] = ans;
     }
    int minCost(vector<int>& nums) {
         n = nums.size();
         dp.resize(n+1,vector<int>(n+1,-1));
         return solve(1,0,nums);
    }
};
