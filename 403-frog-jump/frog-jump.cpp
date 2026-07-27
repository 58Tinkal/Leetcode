class Solution {
public:
    int dp[2005][2005];
    unordered_map<int, int> mp;
    int n;

    bool solve(int idx, int jump, vector<int>& stones) {
        if (idx == n - 1)
            return true;

        if (dp[idx][jump] != -1)
            return dp[idx][jump];

        bool ans = false;

        if (jump - 1 > 0 && mp.count(stones[idx] + jump - 1)) {
            ans |= solve(mp[stones[idx] + jump - 1], jump - 1, stones);
        }

        if (jump > 0 && mp.count(stones[idx] + jump)) {
            ans |= solve(mp[stones[idx] + jump], jump, stones);
        }

        if (jump + 1 > 0 && mp.count(stones[idx] + jump + 1)) {
            ans |= solve(mp[stones[idx] + jump + 1], jump + 1, stones);
        }

        return dp[idx][jump] = ans;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;

        return solve(0, 0, stones);
    }
};