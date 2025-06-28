class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v, v1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0 && k > 0; i--) {
            v1.push_back(v[i]);
            k--;
        }
        sort(v1.begin(), v1.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        vector<int> ans;
        for (auto& it : v1) {
            ans.push_back(it.first);
        }
        return ans;
    }
};