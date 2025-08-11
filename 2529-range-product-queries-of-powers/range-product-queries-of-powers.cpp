class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> a;
        for (int i = 30; i >= 0; i--) {
            if ((1 << i) > n)
                continue;
            a.push_back((1 << i));
            n -= (1 << i);
            if (n == 0)
                break;
        }
        sort(a.begin(), a.end());
        vector<int> ans;
        for (auto it : queries) {
            long long res = 1;
            for (int i = it[0]; i <= it[1]; i++) {
                res = (res * a[i]) % mod;
            }
            ans.push_back(res);
        }
        return ans;
    }
};