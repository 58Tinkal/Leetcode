class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];
            int it =
                lower_bound(nums.begin(), nums.end(), a + b) - nums.begin() - 1;
            if (it <= i + 1)
                continue;
            ans = max(ans, a + b + nums[it]);
        }
        return ans;
    }
};