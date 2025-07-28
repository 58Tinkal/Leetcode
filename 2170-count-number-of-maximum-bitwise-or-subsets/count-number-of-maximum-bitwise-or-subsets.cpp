class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int S=0,cnt=0;
        for(auto it:nums) S|=it;
        int n=nums.size();
        int s=1<<n;
        for (int j=0;j<s;j++) {
        int s1=0;
        for (int i = 0; i < n; ++i) {
            if (j&(1<<i)) {
                s1|=nums[i];
            }
        }
        if(s1==S) cnt++;
    }
    return cnt;
    }
};