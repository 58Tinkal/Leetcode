class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long ans = 0;
        long long c = 0; // count the no of node for which if we apply xor it
                         // will increase
        long long d =
            INT_MAX; // to keep the track which node should be deccarded so that
                     // it there should be minimum losses
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] ^ k) > nums[i])
                c++;
            ans += max(nums[i], nums[i] ^ k);
            d = min(d, (long long)abs(nums[i] - (nums[i] ^ k)));
        }
        // if c%2==0 then we have not to sacrifice any losses
        if (c % 2 == 0)
            return ans;
        return ans - d;
    }
};