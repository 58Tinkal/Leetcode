class Solution {
public:
    int countGoodTriplets(vector<int>& nums, int a, int b, int c) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (abs(nums[i] - nums[j]) > a)
                        continue;
                    if (abs(nums[j] - nums[k]) > b)
                        continue;
                    if (abs(nums[i] - nums[k]) > c)
                        continue;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};