class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        if (n % 2 == 0 && m % 2 == 0)
            return ans;
        for (auto it : nums1)
            if (m % 2 == 1)
                ans ^= it;
        for (auto it : nums2)
            if (n % 2 == 1)
                ans ^= it;
        cout << ans << endl;
        return ans;
    }
};