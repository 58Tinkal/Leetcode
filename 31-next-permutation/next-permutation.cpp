class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for(;i>0;i--){
                if(nums[i] > nums[i-1]){
                    break;
                }
        }
        cout<<i<<' ';

        // int j = i-1;
        if(i == 0)  {sort(nums.begin(), nums.end()); return;}

        sort(nums.begin()+i, nums.end());

        for(int k=i;k<nums.size();k++){
            if(nums[i-1] < nums[k]){
                swap(nums[i-1], nums[k]);
                return;
            }
        }
    }
};
