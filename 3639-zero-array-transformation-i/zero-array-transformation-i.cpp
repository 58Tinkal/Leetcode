class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> p(n);
        for (auto it : q) {
            if (it[1] == n - 1) {
                p[it[0]] += 1;
            } else {
                p[it[0]] += 1;
                p[it[1] + 1] += -1;
            }
        }
        for (int i = 1; i < n; i++) {
            p[i] += p[i - 1];
        }
        for (auto it : p)
            cout << it << ' ';
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                continue;
            if (nums[i] > p[i])
                return false;
        }
        return true;
    }
};