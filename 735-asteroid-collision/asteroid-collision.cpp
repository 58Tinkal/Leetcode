class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> v;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] > 0)
                v.push_back(a[i]);
            else {
                while (!v.empty() && v.back() > 0 && v.back() < abs(a[i]))
                    v.pop_back();
                if (!v.empty() && v.back() == abs(a[i]))
                    v.pop_back();
                else if (v.empty() || v.back() < 0)
                    v.push_back(a[i]);
            }
        }
        return v;
    }
};