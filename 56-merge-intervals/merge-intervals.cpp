class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<vector<int>> ans;
        int l = a[0][0];
        int r = a[0][1];
        for (int i = 1; i < n; i++) {
            if (r < a[i][0]) {
                ans.push_back({l, r});
                l = a[i][0];
                r = a[i][1];
            } else {
                r = max(r,a[i][1]);
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};