class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(
            nums.begin(), nums.end());
        int ans = 0;

        while (pq.top() < k) {
            if (pq.size() == 1 || pq.top() >= k)
                return ans;

            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();

            pq.push(a * 2 + b);
            ans++;
        }
        return ans;
    }
};
