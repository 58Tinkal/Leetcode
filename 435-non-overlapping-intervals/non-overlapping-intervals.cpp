class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        vector<pair<int, int>> a;
        for (int i = 0; i < in.size(); i++) {
            a.push_back({in[i][1], i});
        }
        sort(a.begin(), a.end());
        int freeTime = a[0].first;
        int ans = 1;
        for (int i = 1; i < a.size(); i++) {
            if (in[a[i].second][0] >= freeTime) {
                freeTime = a[i].first;
                ans++;
            }
        }
        return in.size() - ans;
    }
};