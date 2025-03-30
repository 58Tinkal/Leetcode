class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int a = nums[i];
           int t = target-a;
            if(m.find(t) != m.end()){
                return {m[t],i};
            }
           m[a] = i;
        }
        return {};
    }
};