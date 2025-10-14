class ExamTracker {
public:
    vector<int> t;
    vector<long long> s;
    ExamTracker() {}

    void record(int time, int score) {
        long long prefix = s.empty() ? 0 : s.back();
        prefix += score;
        t.push_back(time);
        s.push_back(prefix);
    }

    long long totalScore(int startTime, int endTime) {
        if (t.empty())
            return 0;

        int l = lower_bound(t.begin(), t.end(), startTime) - t.begin();
        int r = upper_bound(t.begin(), t.end(), endTime) - t.begin();

        if (r == 0)
            return 0;
        r--;
        if (l == 0)
            return s[r];
        return s[r] - s[l - 1];
    }
};
