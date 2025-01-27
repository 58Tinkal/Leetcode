class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> dist(n, vector<bool>(n, false));
        for (auto it : prerequisites) {
            dist[it[0]][it[1]] = true;
        }
        for (int i = 0; i < n; i++) {
            dist[i][i] = true;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!dist[i][via] || !dist[via][j])
                        continue;
                    dist[i][j] = dist[i][j] || (dist[i][via] && dist[via][j]);
                }
            }
        }
        vector<bool> ans;
        for (auto it : queries){
            ans.push_back(dist[it[0]][it[1]]);
        }
        return ans;
    }
};