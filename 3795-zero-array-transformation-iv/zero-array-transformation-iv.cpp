class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        // dp[j][s] will be true if we can sum exactly s for index j using some queries
        vector<vector<bool>> dp(n);
        for (int j = 0; j < n; j++) {
            dp[j].resize(nums[j] + 1, false);
            dp[j][0] = true;
        }
        
        // If nums is already a Zero Array, return 0
        bool alreadyZero = true;
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) { 
                alreadyZero = false; 
                break; 
            }
        }
        if (alreadyZero) return 0;
        
        // Process queries one by one
        for (int k = 1; k <= m; k++) {
            int l = queries[k - 1][0], r = queries[k - 1][1], v = queries[k - 1][2];
            // For each index in the current query's range, update its dp table.
            for (int j = l; j <= r; j++) {
                // Update in reverse order to avoid reusing the same query multiple times
                for (int s = nums[j] - v; s >= 0; s--) {
                    if (dp[j][s]) {
                        dp[j][s + v] = true;
                    }
                }
            }
            // Check if all indices can sum to exactly nums[j]
            bool allZero = true;
            for (int j = 0; j < n; j++) {
                if (!dp[j][nums[j]]) {
                    allZero = false;
                    break;
                }
            }
            if (allZero) return k;
        }
        
        return -1;
    }
};
