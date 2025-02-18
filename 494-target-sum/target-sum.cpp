class Solution {
public:
    int ans = 0;
    void solve(int idx,vector<int>& nums, int t, int sum){
        if(idx == nums.size()){
            if(sum == t) ans+=1;
            return;
        }    
        solve(idx+1,nums,t,sum+nums[idx]);
        solve(idx+1,nums,t,sum-nums[idx]);    
    }
    int findTargetSumWays(vector<int>& nums, int t) {
        solve(0,nums,t,0);
        return ans;
    }
};