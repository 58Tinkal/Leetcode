class Solution {
public:
    long long maxPoints(vector<int>& a, vector<int>& b, int k) {
        long long ans = 0;
        int n = a.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({(a[i] - b[i]), i});
        }
        while (!pq.empty() && k > 0) {
            auto it = pq.top();
            pq.pop();
            k--;
            ans += a[it.second];
        }
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ans += max(a[it.second], b[it.second]);
        }
        return ans;
    }
};