class Solution {
public:
    double gain(int p, int t) {
        double cur = (double)p / t;
        double after = (double)(p + 1) / (t + 1);
        return after - cur;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < n; ++i) {
            double g = gain(classes[i][0], classes[i][1]);
            pq.push({g, i});
        }

        while (extraStudents-- > 0) {
            auto top = pq.top();
            pq.pop();
            int idx = top.second;
            classes[idx][0] += 1;
            classes[idx][1] += 1;
            double newg = gain(classes[idx][0], classes[idx][1]);
            pq.push({newg, idx});
        }
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += (double)classes[i][0] / classes[i][1];
        }
        return sum / n;
    }
};