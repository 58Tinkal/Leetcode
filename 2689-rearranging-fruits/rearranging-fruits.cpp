class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> m;
        int n = basket1.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            m[basket1[i]]++;
            mini = min(mini, basket1[i]);
        }
        for (int i = 0; i < n; i++) {
            m[basket2[i]]--;
            mini = min(mini, basket2[i]);
        }
        vector<int> v;
        for (auto& it : m) {
            if (it.second % 2 == 1) {
                return -1;
            }
            for (int i = 0; i < abs(it.second) / 2; i++) {
                v.push_back(it.first);
            }
        }
        long long ans = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() / 2; i++) {
            ans += min(v[i], 2 * mini);
        }
        return ans;
    }
};