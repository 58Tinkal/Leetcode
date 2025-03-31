class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> a;
        int n = weights.size();
        for (int i = 0; i < weights.size() - 1; i++) {
            a.push_back(weights[i] + weights[i + 1]);
        }
        sort(a.begin(), a.end());
        long maxSum = 0;
        long minSum = 0;

        for (int i = 0; i < k - 1; i++) {
            minSum += a[i];
            maxSum += a[n - i - 2];
        }
        return maxSum - minSum;
    }
};