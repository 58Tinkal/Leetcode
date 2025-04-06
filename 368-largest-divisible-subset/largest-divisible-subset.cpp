class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        int maxi = 1, last_idx = 0;
        for (int i = 1; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                last_idx = i;
            }
        }
        vector<int> lds;
        while (hash[last_idx] != last_idx) {
            lds.push_back(nums[last_idx]);
            last_idx = hash[last_idx];
        }
        lds.push_back(nums[last_idx]);
        reverse(lds.begin(), lds.end());
        // maxi will give the length
        cout<<maxi<<endl;
        return lds;
    }
};
