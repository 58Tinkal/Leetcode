class TreeAncestor {
public:
    int MAX = 17;
    vector<vector<int>> table;
    void build(vector<int>& p) {
        int n = p.size();
        table = vector<vector<int>>(MAX, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            table[0][i] = p[i];
        }
        table[0][0] = -1;
        // table[i][j] => i th parent of t th node;
        for (int i = 1; i < MAX; i++) {
            for (int j = 0; j < n; j++) {
                if (table[i - 1][j] == -1)
                    table[i - 1][j] = -1;
                else
                    table[i][j] = table[i - 1][table[i - 1][j]];
            }
        }
        return;
    }
    int query(int node, int k) {
        for (int i = 0; i < MAX; i++) {
            int mask = (1 << i);
            if ((mask & k) > 0) {
                node = table[i][node];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
    TreeAncestor(int n, vector<int>& parent) { build(parent); }

    int getKthAncestor(int node, int k) { return query(node, k); }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */