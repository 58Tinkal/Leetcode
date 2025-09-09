class Solution {
public:
    int MOD = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, 0);

        dp[1] = 1;
        
        int count = 0; 

        for (int day = 2; day <= n; day++) {
            
            if (day - delay > 0) {
                count = (count + dp[day - delay]) % MOD;
            }
            if (day - forget > 0) {
                count = (count - dp[day - forget] + MOD) % MOD;
            }
            dp[day] = count; 
        }

        int result = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                result = (result + dp[day]) % MOD;
            }
        }

        return result;
    }
};
