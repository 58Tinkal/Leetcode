class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int val) {
        int n = nums.size();
        multiset<long long> s;

       
        for (int i = 0; i <= min(k, n - 1); i++) {
            long long num = nums[i];
            auto it = s.lower_bound(num - val);
            if (it != s.end() && *it <= num + val)
                return true;
            s.insert(num);
        }

        int st = 0;
        for (int i = k + 1; i < n; i++) {
            s.erase(s.find(nums[st]));
            st++;

            long long num = nums[i];
            auto it = s.lower_bound(num - val);
            if (it != s.end() && *it <= num + val)
                return true;

            s.insert(num);
        }

        return false;
    }
};
