class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        multiset<int> s(t.begin(), t.end());
        sort(p.begin(), p.end());
        int ans = 0;
        for (int i = 0; i < p.size(); i++) {
            auto it = s.lower_bound(p[i]);
            if (it == s.end()) {
                return ans;
            } else {
                ans++;
                s.erase(it);
            }
        }
        return ans;
    }
};