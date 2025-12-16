class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        a.insert(a.begin(), b);
        sort(a.begin(), a.end());

        vector<vector<int>> ans;

        int l = a[0][0], h = a[0][1];

        for (int i = 1; i < a.size(); i++) {
            if (a[i][0] > h) {
                ans.push_back({l, h});
                l = a[i][0];
                h = a[i][1];
            } else {
                h = max(h, a[i][1]);
            }
        }

        ans.push_back({l, h});
        return ans;
    }
};
