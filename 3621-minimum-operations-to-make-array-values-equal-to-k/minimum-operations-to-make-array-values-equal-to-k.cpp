class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k){
                return -1;
            }
            s.insert(nums[i]);
        }
        if(*s.begin()==k) return s.size()-1;
        return s.size();
    }
};