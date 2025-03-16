class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        for (int q : queries) { 
            int val = nums[q];
            vector<int> &v = m[val];
            if (v.size() < 2) {
                ans.push_back(-1);
                continue;
            }
        
            auto itt = lower_bound(v.begin(), v.end(), q);
            int idx = itt - v.begin();
            
            int left = v[(idx - 1 + v.size()) % v.size()];
            int right = v[(idx + 1) % v.size()];
            
            int dLeft = min(abs(q - left), n - abs(q - left));
            int dRight = min(abs(q - right), n - abs(q - right));
            
            ans.push_back(min(dLeft, dRight));
        }
        return ans;
    }
};
