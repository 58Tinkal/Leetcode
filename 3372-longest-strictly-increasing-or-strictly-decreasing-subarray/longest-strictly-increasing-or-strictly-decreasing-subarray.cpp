class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int l = 1;
        for(int i=0;i<n-1;i++){
             if(nums[i]>nums[i+1]) l++;
             else{
                ans = max(l,ans);
                l=1;
             }
        }
        ans = max(ans,l);
        l=1;
        for(int i=0;i<n-1;i++){
             if(nums[i]<nums[i+1]) l++;
             else{
                ans = max(l,ans);
                l=1;
             }
        }
         ans = max(ans,l);
        return ans;
    }
};