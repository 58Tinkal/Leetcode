class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefix(n, 0), sufix(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                prefix[i] = grid[0][0];
            else
                prefix[i] = prefix[i - 1] + grid[0][i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                sufix[i] = grid[1][n-1];
            else
                sufix[i] = sufix[i + 1] + grid[1][i];
        }
        long long ans = 1e11;
        long long res = 0;
        for(int i=0;i<n;i++){
            res = max(prefix[n-1] - prefix[i], sufix[0] - sufix[i]);
            ans = min(ans,res);
        }
       return ans;
    }
};