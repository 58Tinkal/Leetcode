class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> ans;
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        for (int i = 0; i < min(n, k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (!pq.empty() && k-- > 0) {
            auto it = pq.top();
            pq.pop();
            int sum = it.first;
            int i = it.second.first;
            int j = it.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < m) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};
