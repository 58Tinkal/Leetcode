class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size())
            return nums;
        unordered_map<int, int> m;
        for (auto& it : nums)
            m[it]++;
        auto cmp = [&m](int a, int b) { return m[a] > m[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto it : m) {
            pq.push(it.first);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> top(k);
        for (int i = k - 1; i >= 0; i--) {
            top[i] = pq.top();
            pq.pop();
        }
        return top;
    }
};