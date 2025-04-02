class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; 
        vector<int> pre(n), suf(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i-1], nums[i-1]); 
        }
        
        suf[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i+1], nums[i+1]); 
        }

        long long m = 0;
        for (int i = 1; i < n - 1; i++) {
            m = max(m, 1LL * (pre[i] - nums[i]) * suf[i]);
        }

        return m;
    }
};
