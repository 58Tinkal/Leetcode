class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> m;  
        set<int> s;      
        int st = 0;
        int n = fruits.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s.size() < 2 || s.count(fruits[i])) {
                s.insert(fruits[i]);
                m[fruits[i]] = i;
            } else {
                ans = max(ans, i - st);
                int minIdx = n;
                int fruitToRemove;
                for (int fruit : s) {
                    if (m[fruit] < minIdx) {
                        minIdx = m[fruit];
                        fruitToRemove = fruit;
                    }
                }

                s.erase(fruitToRemove);
                m.erase(fruitToRemove);

                st = minIdx + 1;

                s.insert(fruits[i]);
                m[fruits[i]] = i;
            }

            ans = max(ans, i - st + 1);
        }

        return ans;
    }
};
