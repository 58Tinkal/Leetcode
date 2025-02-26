class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        int s = 0;
        for(int i=0;i<nums.size();i++){
            s += nums[i];
            mx = max(mx,s);
            if(s<0) s = 0;
        }
        s = 0;
         for(int i=0;i<nums.size();i++){
            s += nums[i];
            mn = min(mn,s);
            if(s>0) s = 0;
        }
        return max(abs(mx),abs(mn));
    }
};