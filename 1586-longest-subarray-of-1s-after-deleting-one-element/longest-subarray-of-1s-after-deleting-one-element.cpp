class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int z = 0;
        int s = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                z++;
            while (z > 1) {
                if (nums[s] == 0) {
                    z--;
                }
                s++;
            }
            ans = max(ans, i - s);
        }
        return ans;
    }
};