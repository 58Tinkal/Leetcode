class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int> a, b;
        // a => 1;
        // b => -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
        if(a.size()==0 || b.size()==0) return true;
        if (a.size() % 2 == 1 && b.size() % 2 == 1) {
            return false;
        }
        int x = 0, y = 0;
        for (int i = 0; a.size() % 2 == 0 && i < a.size(); i += 2) {
            x += a[i + 1] - a[i];
        }
        for (int i = 0; b.size() % 2 == 0 && i < b.size(); i += 2) {
            y += b[i + 1] - b[i];
        }
        cout << x << ' ' << y << endl;

        if (x <= k && a.size() != 0 && a.size() % 2 == 0)
            return true;
        if (y <= k && b.size() != 0 && b.size() % 2 == 0)
            return true;
        return false;
    }
};