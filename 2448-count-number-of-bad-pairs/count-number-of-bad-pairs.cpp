class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            nums[i] -= i;
        }
        long  long n = nums.size();
        map<long  long,long  long>m;
        long  long x = 0;
        for(auto it:nums){
           if(m.find(it) != m.end()){
            x+=m[it];
           }
            m[it]++;
        }
        long  long ans = n*(n-1)/2 - x;
        return ans;
    }
};