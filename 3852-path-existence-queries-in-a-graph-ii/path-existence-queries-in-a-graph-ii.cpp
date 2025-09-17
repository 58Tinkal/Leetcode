class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[v[i].second] = i;
        }
        vector<vector<int>> dp(18, vector<int>(n));
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(v.begin(), v.end(),
                                  make_pair(v[i].first + maxDiff, INT_MAX));
            dp[0][i] = it - v.begin() - 1;
        }
        for (int i = 1; i <= 17; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
        vector<int> ans;
        for (auto it : queries) {
            int a = pos[it[0]];
            int b = pos[it[1]];
            if (a == b) {
                ans.push_back(0);
                continue;
            }
            if (a > b)
                swap(a, b);
            if (dp[17][a] < b) {
                ans.push_back(-1);
                continue;
            }
            int dist = 0;
            for (int i = 17; i >= 0; i--) {
                if (dp[i][a] < b) {
                    dist += (1 << i);
                    a = dp[i][a];
                }
            }
            ans.push_back(dist + 1);
        }
        return ans;
    }
};