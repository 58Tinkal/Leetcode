class Solution {
public:
    vector<int> findFactors(int n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int,int>m;
        for(int i=0;i<elements.size();i++){
            if(m.find(elements[i]) == m.end()){
                 m[elements[i]] = i;
            }
        }
        vector<int>ans;
        for(int i=0;i<groups.size();i++){
            vector<int>fac = findFactors(groups[i]);
            int res = INT_MAX;
            for(auto it:fac){
                if(m.find(it) != m.end()){
                    res = min(res,m[it]);
                }
            }
            if(res == INT_MAX) ans.push_back(-1);
            else ans.push_back(res);
        }
        return ans;
    }
};