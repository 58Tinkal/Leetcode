class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int s = 0;
        int length = 0;
        int mask = 0; // To chech which bit is used
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            while ((mask & nums[i]) != 0) {
                // mask ^ nums[s] => flip the bit from mask which are also same
                // as mask
                mask ^= nums[s];
                s++;
            }

            mask |= nums[i];
            length = max(length, i - s + 1);
        }
        return length;
    }
};