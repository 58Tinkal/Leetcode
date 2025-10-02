class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> m;
        int n = row.size();
        for (int i = 0; i < n; i++) {
            m[row[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < n;) {
            if (row[i] % 2 == 0) {
                if (row[i + 1] == row[i] + 1) {
                    i += 2;
                } else {
                    swaps++;
                    int x = m[row[i] + 1];
                    int y = i + 1;

                    swap(row[y], row[x]);

                    m[row[x]] = x;
                    m[row[y]] = y;
                    i += 2;
                }
            } else {
                if (row[i + 1] == row[i] - 1) {
                    i += 2;
                } else {
                    swaps++;
                    int x = m[row[i] - 1];
                    int y = i + 1;
                    swap(row[y], row[x]);
                    m[row[x]] = x;
                    m[row[y]] = y;
                    i += 2;
                }
            }
        }
        return swaps;
    }
};
