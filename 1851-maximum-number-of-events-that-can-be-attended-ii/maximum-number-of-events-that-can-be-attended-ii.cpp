class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> e;
    int n, K;
    vector<int> a;
    int indexFirstGreater(const vector<int>& a, int x) {
        return int(upper_bound(a.begin(), a.end(), x) - a.begin()); 
    }

    int solve(int idx, int k) {
        if (k == 0 || idx >= n)
            return 0;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int j = indexFirstGreater(a, e[idx][1]); 
        int take = e[idx][2] + solve(j, k - 1);
        int nottake = solve(idx + 1, k);

        return dp[idx][k] = max(take, nottake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        e = events;
        K = k;

        sort(e.begin(), e.end()); // sort by start time (first column)
        a.clear();
        for (auto& it : e)
            a.push_back(it[0]);

        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(0, k);
    }
};