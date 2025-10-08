class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;
        for (int i = 0; i < spells.size(); i++) {
            long long x = (success + spells[i] - 1) / spells[i];
            int idx = lower_bound(potions.begin(), potions.end(), x) -
                      potions.begin();

            ans.push_back(n - idx);
        }
        return ans;
    }
};