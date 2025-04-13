class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>a;
        for(int i=0;i<n;i++){
            for(auto it:s){
                a.insert(it^nums[i]);
            }
        }
        return a.size();
    }
};