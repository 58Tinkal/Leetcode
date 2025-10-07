class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        map<int, int> last;       
        set<int> m;              
        unordered_set<int> s;     
        vector<int> ans(n, 1);    

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                m.insert(i); 
            } else {
                ans[i] = -1; 
                int lake = rains[i];

                if (s.find(lake) != s.end()) {
                    auto it = m.upper_bound(last[lake]);
                    if (it == m.end()) {
                        return {};
                    }
                    ans[*it] = lake; 
                    m.erase(it);    
                }
                s.insert(lake);       
                last[lake] = i;      
            }
        }

        return ans;
    }
};
