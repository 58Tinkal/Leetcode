class Solution {
public:
    int ans = 0;
    int n;

    void fun(int idx, int score, vector<bool>& used,
             vector<vector<int>>& students, vector<vector<int>>& mentors) {
        if (idx == n) {
            ans = max(ans, score);
            return;
        }

        for (int i = 0; i < mentors.size(); i++) {
            if (used[i])
                continue;

            int currScore = 0;
            for (int j = 0; j < mentors[0].size(); j++) {
                currScore += (students[idx][j] == mentors[i][j]);
            }

            used[i] = true;
            fun(idx + 1, score + currScore, used, students, mentors);
            used[i] = false;
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students,
                            vector<vector<int>>& mentors) {
        n = students.size();
        vector<bool> used(n, false);
        fun(0, 0, used, students, mentors);
        return ans;
    }
};
