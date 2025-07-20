class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<tuple<int, int, int>> v;
        for (auto& b : buildings) {
            int x1 = b[0], x2 = b[1], h = b[2];
            v.emplace_back(x1, -h, 1); 
            v.emplace_back(x2, h, 0);   
        }
        
        sort(v.begin(), v.end());

        multiset<int> heights = {0};
        vector<vector<int>> ans;
        int prevMax = 0;

        for (auto [x, h, type] : v) {
            if (type == 1) {
                heights.insert(-h); 
            } else {
                heights.erase(heights.find(h));
            }

            int currMax = *heights.rbegin();
            if (currMax != prevMax) {
                ans.push_back({x, currMax});
                prevMax = currMax;
            }
        }

        return ans;
    }
};
