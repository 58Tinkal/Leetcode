class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (j == k)
                        continue;
                    double area = points[i][0] * (points[j][1] - points[k][1]) +
                                  points[j][0] * (points[k][1] - points[i][1]) +
                                  points[k][0] * (points[i][1] - points[j][1]);
                    if (area < 1e-5)
                        continue;
                    ans = max(ans, fabs(area) / 2.0);
                }
            }
        }
        return ans;
    }
};