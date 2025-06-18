class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i+=3){
            if(abs(nums[i]-nums[i+1])>k || abs(nums[i+1]-nums[i+2])>k || abs(nums[i]-nums[i+2])>k){
                continue;
            }
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        if(ans.size() < n/3) return {};
        return ans;
    }
};