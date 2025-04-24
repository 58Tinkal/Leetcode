class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int k = s.size();
        map<int, int> m;
        int n = nums.size();
        int st = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
            if (m.size() == k)
                ans += n - i;
            while (m.size() >= k) {
                if (m[nums[st]] > 1) {
                    m[nums[st]]--;
                } else if (m[nums[st]] == 1) {
                    m.erase(nums[st]);
                }
                st++;
                if (m.size() == k)
                    ans += n - i;
            }
        }
        return ans;
    }
};