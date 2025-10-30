class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        int mx = 0;
        for (auto& it : target) {
            if (mx < it) {
                ans += it - mx;
            }
            mx = it;
        }
        return ans;
    }
};