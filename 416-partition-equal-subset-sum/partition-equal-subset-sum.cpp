class Solution {
public:
    bool memoziation(int i, vector<vector<int>>& dp, int target,
                     vector<int>& nums) {
        if (target == 0)
            return true;
        if (i == 0)
            return target == nums[0];
        if (dp[i][target] != -1)
            return dp[i][target];
        bool nottake = memoziation(i - 1, dp, target, nums);
        bool take = false;
        if (target >= nums[i])
            take = memoziation(i - 1, dp, target - nums[i], nums);
        return dp[i][target] = nottake || take;
    }
    bool tabulation(vector<int>& nums, int target) {
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= target)
            dp[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (j - nums[i] >= 0)
                    take = dp[i - 1][j - nums[i]];
                dp[i][j] = take || notTake;
            }
        }
        return dp[nums.size() - 1][target];
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for (auto it : nums)
            s += it;
        if (s % 2 == 1)
            return false;

        vector<vector<int>> dp(nums.size(), vector<int>(s / 2 + 1, -1));
        int n = nums.size();
        return memoziation(n - 1, dp, s / 2, nums);
        //  return tabulation(nums,s/2);
    }
};