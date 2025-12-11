class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> x, y;
        for (auto it : buildings) {
            x[it[0]].push_back(it[1]);
            y[it[1]].push_back(it[0]);
        }
        for(auto &it:x){
            sort(it.second.begin(),it.second.end());
        }
        for(auto &it:y){
            sort(it.second.begin(),it.second.end());
        }
        int ans = 0;
        for (auto& it : buildings) {
            vector<int>& X = x[it[0]];
            vector<int>& Y = y[it[1]];
            int idx1 = lower_bound(X.begin(), X.end(), it[1]) - X.begin();
            int idx2 = lower_bound(Y.begin(), Y.end(), it[0]) - Y.begin();
            if (idx1 == 0 || idx1 == X.size() - 1 || idx2 == 0 ||
                idx2 == Y.size() - 1) {
                continue;
            }
            ans++;
        }
        return ans;
    }
};