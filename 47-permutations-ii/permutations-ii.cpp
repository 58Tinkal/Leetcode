class Solution {
public:
    vector<vector<int>> ans;
    void solve(map<int, int>& m, vector<int>& temp, int n) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (auto& it : m) {
            if (it.second == 0)
                continue;
            it.second--;
            temp.push_back(it.first);
            solve(m, temp, n);
            it.second++;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> m;
        for (auto& it : nums) {
            m[it]++;
        }

        vector<int> temp;
        solve(m, temp, nums.size());
        return ans;
    }
};