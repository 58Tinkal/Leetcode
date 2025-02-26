class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = 0;
        int mn = 0;
        int s = 0;
        for(auto &it:nums){
            s += it;
            if(mx<s) mx = s;
            if(mn>s) mn = s;
        }
        return mx-mn;
    }
};