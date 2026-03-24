class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        set<int> a;
        int x = INT_MAX;
        for (auto it : nums1) {
            if (it % 2 == 0) {
                a.insert(it);
            } else {
                x = min(x, it);
            }
        }

        if (a.size() == 0 || x == INT_MAX) {
            return true;
        }
        for (auto it : a) {
            if (it - x < 1) {
                return false;
            }
        }
        return true;
    }
};