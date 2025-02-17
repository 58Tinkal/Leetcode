class Solution {
public:
    int sum=0;
    vector<bool>vis;
    bool solve(int idx,vector<int>& nums,int k,int s){
        if(k==0) return true;
        if(s==sum) return solve(0,nums,k-1,s=0);
        for(int i=idx;i<nums.size();i++){
            if(vis[i] || s+nums[i]>sum)  continue;
            vis[i] = true;
           // s+=nums[i];
            if(solve(i+1,nums,k,s+nums[i])) return true;
            vis[i] = false;
          //  s-=nums[i];
           if (s == 0) return false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
      
        for(auto &it:nums) sum+=it;
        if(sum%k != 0 || nums.size() < k){
            return false;
        }
        sum = sum/k;
        vis = vector<bool>(nums.size(),false);
      
        return solve(0,nums,k,0);
    }
};