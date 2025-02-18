class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& c, int t, vector<int>& temp, int sum, int start) {
        if (sum == t) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < c.size(); i++) {
            if (i > start && c[i] == c[i - 1]) continue;  
            if (sum + c[i] > t) break;

            temp.push_back(c[i]);
            solve(c, t, temp, sum + c[i], i + 1);  
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end()); 
        vector<int> temp;
        solve(c, t, temp, 0, 0);
        return ans;
    }
};
