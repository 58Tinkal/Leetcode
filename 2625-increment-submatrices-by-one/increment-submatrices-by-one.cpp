class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (auto it : queries) {
            for (int i = it[0]; i <= it[2]; i++) {
                ans[i][it[1]] += 1;
                if (it[3] + 1 < n) {
                    ans[i][it[3] + 1] -= 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                ans[i][j] += ans[i][j - 1];
            }
        }
        return ans;
    }
};