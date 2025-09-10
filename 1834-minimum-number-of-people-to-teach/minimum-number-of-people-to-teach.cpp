class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) {
        set<int> t;  
        for (auto &fr : f) {
            int u = fr[0] - 1; 
            int v = fr[1] - 1;

            set<int> s(l[u].begin(), l[u].end());
            s.insert(l[v].begin(), l[v].end());

            if (s.size() == l[u].size() + l[v].size()) {
                t.insert(u);
                t.insert(v);
            }
        }

        if (t.empty()) return 0;

        vector<int> lau(n + 1, 0); 
        for (auto person : t) {
            for (auto lang : l[person]) {
                lau[lang]++;
            }
        }

        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            maxi = max(maxi, lau[i]);
        }

        return (int)t.size() - maxi;
    }
};
