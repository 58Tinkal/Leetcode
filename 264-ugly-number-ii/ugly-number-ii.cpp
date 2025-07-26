class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long> seen;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        pq.push(1);
        seen.insert(1);
        long long ugly = 1;

        for (int i = 0; i < n; ++i) {
            ugly = pq.top(); pq.pop();

            if (seen.insert(ugly * 2).second) pq.push(ugly * 2);
            if (seen.insert(ugly * 3).second) pq.push(ugly * 3);
            if (seen.insert(ugly * 5).second) pq.push(ugly * 5);
        }

        return (int)ugly;
    }
};
