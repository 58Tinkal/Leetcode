class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = 0;
        int sum = 0, maxSum = 0;
        unordered_set<int> seen;

        while (e < n) {
            if (seen.count(nums[e]) == 0) {
                sum += nums[e];
                seen.insert(nums[e]);
                maxSum = max(maxSum, sum);
                e++;
            } else {
                // remove nums[s] from window
                seen.erase(nums[s]);
                sum -= nums[s];
                s++;
            }
        }

        return maxSum;
    }
};
