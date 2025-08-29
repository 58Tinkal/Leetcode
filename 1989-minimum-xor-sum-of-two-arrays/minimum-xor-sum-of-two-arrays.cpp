class Solution {
private:
    int n;
    vector<vector<int>> dp;
    
    int solve(int idx, int mask, vector<int>& nums1, vector<int>& nums2) {
        if (idx == n) return 0;
        if (dp[idx][mask] != -1) return dp[idx][mask];
        
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) { 
                ans = min(ans, (nums1[idx] ^ nums2[i]) + solve(idx + 1, mask | (1 << i), nums1, nums2));
            }
        }
        return dp[idx][mask] = ans;
    }
    
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums2.size();
        dp.assign(n, vector<int>(1 << n, -1));
        return solve(0, 0, nums1, nums2);
    }
};
