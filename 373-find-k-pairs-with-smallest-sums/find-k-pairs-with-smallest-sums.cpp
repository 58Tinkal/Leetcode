class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size(), m = nums2.size();
        if (n == 0 || m == 0) return ans;

        using pii = pair<int, pair<int, int>>; // sum, {i, j}
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        // Start with first element of nums2 for each nums1[i]
        for (int i = 0; i < min(n, k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (!pq.empty() && k-- > 0) {
            auto [sum, indices] = pq.top();
            pq.pop();
            int i = indices.first;
            int j = indices.second;

            ans.push_back({nums1[i], nums2[j]});

            // Move next in nums2 for same nums1[i]
            if (j + 1 < m) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};
