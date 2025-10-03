class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> basic(31, 0);
        for (auto it : nums) {
            for (int i = 30; i >= 0; i--) {
                if (((1 << i) & it) == 0) {
                    continue; // no controling bit so continue;
                }
                if (basic[i] == 0) {
                    // no basic for this bit
                    basic[i] = it;
                    break;
                }
                it ^= basic[i];
            }
        }
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            ans = max(ans, ans ^ basic[i]);
        }
        return ans;
    }
};