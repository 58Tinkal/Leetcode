class Solution {
public:
    long long ans = 0;
    int removeSquareFactors(int n) {
        int largestSquare = 1;
        for (int i = 1; i * i <= n; i++) {
            int sq = i * i;
            if (n % sq == 0) {
                largestSquare = sq;
            }
        }
        return n / largestSquare;
    }
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& nums,
             unordered_map<int, long long>& m) {

        long long count = m.count(nums[node]) ? m[nums[node]] : 0;
        ans += count;
        m[nums[node]]++;
        for (auto it : adj[node]) {
            if (it == parent)
                continue;
            dfs(it, node, adj, nums, m);
        }
        if (--m[nums[node]] == 0) {
            m.erase(nums[node]);
        }
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges,
                             vector<int>& nums) {
        for (auto& it : nums) {
            it = removeSquareFactors(it);
        }
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map<int, long long> m;
        dfs(0, -1, adj, nums, m);
        return ans;
    }
};