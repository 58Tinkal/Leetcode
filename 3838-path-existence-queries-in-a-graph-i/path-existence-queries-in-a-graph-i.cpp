
class Solution {
private:
    vector<int> parent, size;
    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void union_by_size(int u, int v) {
        int u_p = findPar(u);
        int v_p = findPar(v);
        if (u_p == v_p)
            return;
        if (size[u_p] < size[v_p]) {
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        } else {
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        }
    }

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        size.assign(n + 1, 1);
        parent.assign(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            if (abs(nums[i] - nums[i + 1]) <= maxDiff) {
                union_by_size(i, i + 1);
            }
        }
        vector<bool> ans;
        for (auto it : queries) {
            int x = findPar(it[0]);
            int y = findPar(it[1]);
            if (x == y) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};