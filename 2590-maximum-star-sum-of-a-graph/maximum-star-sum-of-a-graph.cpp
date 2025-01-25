class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if (edges.size() == 0) {
            return *max_element(vals.begin(), vals.end());
        }
        int ans = INT_MIN;
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (auto it : adj[i]) {
                temp.push_back(vals[it]);
            }
            sort(temp.begin(), temp.end(), greater<int>());
            int a = vals[i];
            ans = max(ans, a);
            int len = min((int)temp.size(), k);
            for (int j = 0; j < len; j++) {
                a += temp[j];
                ans = max(ans, a);
            }
            ans = max(ans, a);
        }
        return ans;
    }
};
