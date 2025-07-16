class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int o = 0, e = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1)
                o++;
            else
                e++;
        }
        int ans = max(o, e);
        map<int, int> m;
        m[nums[0] % 2] = 1;
        for (int i = 1; i < n; i++) {
            int  p = 1;
            if (m.find(1 - nums[i] % 2) != m.end()) {
                p += m[1 - nums[i] % 2];
                m[nums[i] % 2] = p;
            } else {
                m[nums[i] % 2] = p;
            }
            ans = max(ans, p);
        }
        return ans;
    }
};