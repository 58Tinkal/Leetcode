class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int it =
                    lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) -
                    nums.begin() - 1;
                if (it - j > 0)
                    ans += it - j;
            }
        }
        return ans;
    }
};