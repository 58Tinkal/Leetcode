class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int l = lower - nums[i];
            int u = upper - nums[i];
            
            auto itl = lower_bound(nums.begin() + i + 1, nums.end(), l);
            auto itu = upper_bound(nums.begin() + i + 1, nums.end(), u);

            ans += itu - itl;
        }

        return ans;
    }
};
