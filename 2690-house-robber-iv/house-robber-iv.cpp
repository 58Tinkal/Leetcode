class Solution {
public:
    bool fun(vector<int>& nums, int k, int mid) {
        int c = 0;
        int n = nums.size();
        int s = -1e9;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                c++;
                i++;
            }
            if (c >= k)
                return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (fun(nums, k, mid)) {
                h = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};