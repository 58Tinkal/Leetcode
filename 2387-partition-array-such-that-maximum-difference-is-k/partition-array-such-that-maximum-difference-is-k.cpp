class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int n = nums.size();
        int c = 0;
        int x = nums[0];
        for(int i=0;i<n;i++){
           if(x-nums[i]>k){
            x = nums[i];
            c++;
           }
        }
        c++;
        return c;
    }
};