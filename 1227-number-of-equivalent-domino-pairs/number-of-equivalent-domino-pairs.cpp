class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        map<string, int> m;
        for (auto& it : dominoes) {
            string s = to_string(it[0] - '0') + to_string(it[1] - '0');
            sort(s.begin(), s.end());
            m[s]++;
        }

        for (auto it : m) {
            cout << it.second << ' ';
            ans += it.second * (it.second - 1) / 2;
        }
        return ans;
    }
};