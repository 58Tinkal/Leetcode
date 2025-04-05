class Solution {
public:
    int n;
    int solve(int idx, int sum, vector<int>& nums) {
        if (idx == n)
            return sum;
        int take = solve(idx + 1, sum ^ nums[idx], nums);
        int notTake = solve(idx + 1, sum, nums);
        return take + notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        return solve(0, 0, nums);
    }
};