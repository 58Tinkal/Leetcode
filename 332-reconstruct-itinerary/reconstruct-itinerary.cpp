class Solution {
public:
    vector<string> ans;

    void dfs(string s, unordered_map<string, multiset<string>>& adj) {
        while (!adj[s].empty()) {
            string next = *adj[s].begin();
            adj[s].erase(adj[s].begin()); 
            dfs(next, adj);
        }
        ans.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        for (auto& it : tickets) {
            adj[it[0]].insert(it[1]);
        }

        dfs("JFK", adj);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
