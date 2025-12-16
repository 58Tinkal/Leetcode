class Solution {
public:
    int solve(vector<int>& a) {
        stack<int> s;
        int n = a.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] > a[i]) {
                int el = s.top();
                s.pop();
                int nse = i;
                int pse = s.empty() ? -1 : s.top();
                ans = max(ans, a[el] * (nse - pse - 1));
            }
            s.push(i);
        }

        while (!s.empty()) {
            int el = s.top();
            s.pop();
            int nse = n;
            int pse = s.empty() ? -1 : s.top();
            ans = max(ans, a[el] * (nse - pse - 1));
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> a(m, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    a[j]++;
                else
                    a[j] = 0;
            }
            ans = max(ans, solve(a));
        }

        return ans;
    }
};
