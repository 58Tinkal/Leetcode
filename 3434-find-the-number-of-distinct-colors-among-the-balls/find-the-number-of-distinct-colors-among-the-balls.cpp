class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> m, s;
        vector<int> ans;
        for (auto it : queries) {
            if (m[it[0]] > 0) {
                auto itt = m[it[0]];
                if (s[itt] == 1)
                    s.erase(itt);
                else
                    s[itt]--;
                m[it[0]] = it[1];
                s[it[1]]++;
            } else {
                m[it[0]] = it[1];
                s[it[1]]++;
            }
            ans.push_back(min(m.size(), s.size()));
        }
        return ans;
    }
};