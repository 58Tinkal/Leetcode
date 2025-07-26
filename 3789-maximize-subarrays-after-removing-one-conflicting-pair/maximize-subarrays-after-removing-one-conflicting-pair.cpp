class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid = 0;

        map<int, vector<int>> m;

        for (auto& it : conflictingPairs) {
            int a = min(it[0], it[1]);
            int b = max(it[0], it[1]);
            m[b].push_back(a);
        }

        int firstmaxConflict = 0;
        int secondmaxConflict = 0;
        vector<long long> extra(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            for (auto& it : m[i]) {
                if (it >= firstmaxConflict) {
                    secondmaxConflict = firstmaxConflict;
                    firstmaxConflict = it;
                } else if (it > secondmaxConflict) {
                    secondmaxConflict = it;
                }
            }

            valid += i - firstmaxConflict;
            extra[firstmaxConflict] += firstmaxConflict - secondmaxConflict;
        }

        return valid + *max_element(extra.begin(), extra.end());
    }
};
