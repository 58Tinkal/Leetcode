class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        if (n == 1) {
            return eventTime - (endTime[0] - startTime[0]);
        }
        int ans = max(startTime[0], eventTime - endTime[n - 1]);

        vector<pair<int, int>> gap;
        gap.push_back({startTime[0], 0});
        for (int i = 1; i < n; i++) {
            int g = startTime[i] - endTime[i - 1];
            ans = max(ans, g);
            gap.push_back({g, i});
        }
        gap.push_back({eventTime - endTime[n - 1], n});
        sort(gap.begin(), gap.end(), greater<pair<int, int>>());
        int ft     = gap[0].first, idx_ft = gap[0].second;
        int sc     = gap[1].first, idx_sc = gap[1].second;
        int th     = gap[2].first, idx_th = gap[2].second;

        for (int i = 0; i < n; i++) {
            int dur = endTime[i] - startTime[i];

            bool flag =
                (dur <= ft && idx_ft != i && idx_ft != i+1) ||
                (dur <= sc && idx_sc != i && idx_sc != i+1) ||
                (dur <= th && idx_th != i && idx_th != i+1);

            int left_gap  = (i == 0 ? startTime[0] : startTime[i] - endTime[i - 1]);
            int right_gap = (i == n - 1 ? eventTime - endTime[n - 1] : startTime[i + 1] - endTime[i]);
            int merged    = left_gap + right_gap + dur;

     
            int best_after_move = flag ? merged : merged - dur;
            ans = max(ans, best_after_move);
        }

        return ans;
    }
};
