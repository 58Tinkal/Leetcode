class Solution {
public:
    vector<int> dp;

    int solve(int idx, vector<int>& startTime, vector<vector<int>>& job) {
        if (idx == startTime.size()) {
            return 0;
        }
        if (dp[idx] != -1) return dp[idx];

        int notTake = solve(idx + 1, startTime, job);

        int i = lower_bound(startTime.begin(), startTime.end(), job[idx][1]) - startTime.begin();
        int take = job[idx][2] + solve(i, startTime, job);

        return dp[idx] = max(notTake, take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        dp = vector<int>(n, -1);

        vector<vector<int>> job;
        for (int i = 0; i < n; i++) {
            job.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(job.begin(), job.end()); 
        for (int i = 0; i < n; i++) {
            startTime[i] = job[i][0]; 
        }

        return solve(0, startTime, job);
    }
};
