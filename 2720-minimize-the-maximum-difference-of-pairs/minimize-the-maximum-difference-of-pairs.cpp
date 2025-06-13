class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());  
        int l = 0;
        int h = nums.back() - nums.front();
        while (l < h) {
            int m = (l + h) / 2;
            int c = 0;
            for (int i = 1; i < nums.size();) {
                if (abs(nums[i] - nums[i - 1]) <= m) {
                    c++;
                    i += 2;
                } else {
                    i++;
                }
            }
            if (c >= p) h = m;
            else l = m + 1;
        }
        return l;
    }
};
