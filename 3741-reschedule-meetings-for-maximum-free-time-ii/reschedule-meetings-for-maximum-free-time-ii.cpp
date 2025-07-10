
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
            ans = max(ans, startTime[i] - endTime[i - 1]);
            gap.push_back({startTime[i] - endTime[i - 1], i});
        }
        gap.push_back({eventTime - endTime[n - 1], n});
        sort(gap.begin(), gap.end(), greater<pair<int, int>>());
        int ft = gap[0].first, idx_ft = gap[0].second;
        int sc = gap[1].first, idx_sc = gap[1].second;
        int th = gap[2].first, idx_th = gap[2].second;
        for (int i = 0; i < n; i++) {
            int mettingSize = endTime[i] - startTime[i];

            bool flag = (i + 1 != idx_ft && i != idx_ft && mettingSize <= ft) ||
                        (i + 1 != idx_sc && i != idx_sc && mettingSize <= sc) ||
                        (i + 1 != idx_th && i != idx_th && mettingSize <= th);
            if (flag) {
                if (i == 0) {
                    ans = max(ans, startTime[1] - (endTime[0] - startTime[0]));
                    ans = max(ans, startTime[1]);
                } else if (i == n - 1) {
                    ans = max(ans, (eventTime - endTime[n - 2]) -
                                       (endTime[n - 1] - startTime[n - 1]));
                    ans = max(ans, eventTime - endTime[n - 2]);
                } else {
                    ans = max(ans, (startTime[i + 1] - endTime[i - 1]) -
                                       (-startTime[i] + endTime[i]));
                    ans = max(ans, startTime[i + 1] - endTime[i - 1]);
                }
            } else {
                if (i == 0) {
                    ans = max(ans, startTime[1] - (endTime[0] - startTime[0]));
                } else if (i == n - 1) {
                    ans = max(ans, (eventTime - endTime[n - 2]) -
                                       (endTime[n - 1] - startTime[n - 1]));
                } else {
                    ans = max(ans, (startTime[i + 1] - endTime[i - 1]) -
                                       (-startTime[i] + endTime[i]));
                }
            }
        }
        return ans;
    }
};
