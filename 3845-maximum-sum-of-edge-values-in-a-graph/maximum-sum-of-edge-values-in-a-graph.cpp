class Solution {
public:
    bool dfs(int i, int p, vector<vector<int>> &adj, vector<bool> &vis, int &cnt) {
        cnt++;
        vis[i] = true;
        bool ans = false;
        for(auto &j : adj[i]) {
            if(j == p) continue;
            if(vis[j]) ans = true;
            else ans |= dfs(j, i, adj, vis, cnt);
        }
        return ans;
    }
    
    long long maxScore(long long n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> vis(n, false);
        vector<int> cycles, chains;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int cnt = 0;
            if(dfs(i, -1, adj, vis, cnt)) cycles.push_back(cnt);
            else chains.push_back(cnt);
        }

        sort(cycles.rbegin(), cycles.rend());
        sort(chains.rbegin(), chains.rend());

        long long ans = 0;
        for(auto x : cycles) {
            ans += n*(n-1 + n-2);
            n -= 3; x -= 3;
            while(x) {
                ans += n*(n+2);
                x--; n--;
            }
            ans += (n+1)*(n+2);
        }
        for(auto x : chains) {
            if(x == 1) break;
            if(x == 2) {
                ans += n*(n-1);
                n -= 2;
                continue;
            }
            ans += n*(n-1 + n-2);
            n -= 3; x -= 3;
            while(x) {
                ans += n*(n+2);
                x--; n--;
            }
        }
        return ans;
    }
};