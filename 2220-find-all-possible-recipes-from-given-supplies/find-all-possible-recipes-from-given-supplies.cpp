class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> s, temp;
        for (int i = 0; i < supplies.size(); i++) {
            s.insert(supplies[i]);
        }

        int n = recipes.size();
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[j])
                    continue;
                string str = recipes[j];
                auto& c = ingredients[j];
                bool f = true;
                for (auto& it : c) {
                    if (s.find(it) == s.end()) {
                        f = false;
                        break;
                    }
                }
                if (f == true && vis[j] == false) {
                    vis[j] = true;
                    s.insert(str);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (vis[i])
                ans.push_back(recipes[i]);
        }
        return ans;
    }
};