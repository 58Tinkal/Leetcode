class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto& it : s) {
            if (s.find(it - 1) == s.end()) {
                int cnt = 1;
                int x = it;
                while (s.find(x + 1) != s.end()) {
                    x++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};