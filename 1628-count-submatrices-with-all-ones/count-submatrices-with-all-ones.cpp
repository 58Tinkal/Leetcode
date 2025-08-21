class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> row(m, 0);
        int ans = 0;
        int cnt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0)
                    row[j] = 0;
                else
                    row[j] += 1;
            }
            stack<pair<int, pair<int, int>>> st;
            st.push({-1, {-1, 0}}); // height, index, prev_cnt;
            for (int j = 0; j < m; j++) {
                while (st.top().first >= row[j]) {
                    st.pop();
                }
                cnt = row[j] * (j - st.top().second.first) +
                      st.top().second.second;
                st.push({row[j], {j, cnt}});
                ans += cnt;
            }
        }
        return ans;
    }
};