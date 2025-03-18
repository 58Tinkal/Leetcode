class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int length = 0;
        int curr_sum = 0;
        int curr_xor = 0;
        // if all bits of x & y are diffrent then x & y = 0
        // and x ^ y == x + y, We will use this property
        for (int i = 0; i < n; i++) {
            curr_sum += nums[i];
            curr_xor ^= nums[i];
            while (curr_sum != curr_xor) {
                curr_sum -= nums[s];
                curr_xor ^= nums[s];
                s++;
            }
            length = max(length, i - s + 1);
        }
        return length;
    }
};