#include <ranges>

static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& qu) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> q;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.push({grid[0][0], {0, 0}});
        vis[0][0] = true;

        vector<pair<int, int>> queries;
        for (int i = 0; i < qu.size(); i++) {
            queries.push_back({qu[i], i});
        }
        sort(queries.begin(), queries.end());

        int cnt = 0;
        unordered_map<int, int> mp;

        for (auto& que : queries) {
            int query_val = que.first;
            int idx = que.second;
            while (!q.empty() && q.top().first < query_val) {
                auto it = q.top();
                q.pop();
                int val = it.first;
                int r = it.second.first;
                int c = it.second.second;

                cnt++;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (isValid(nr, nc, n, m) && !vis[nr][nc]) {
                        q.push({grid[nr][nc], {nr, nc}});
                        vis[nr][nc] = true;
                    }
                }
            }
            mp[query_val] = cnt;
        }

        vector<int> ans(qu.size());
        for (int i = 0; i < qu.size(); i++) {
            ans[i] = mp[qu[i]];
        }
        return ans;
    }
};
