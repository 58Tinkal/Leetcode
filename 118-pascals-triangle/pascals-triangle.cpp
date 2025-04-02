class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            vector<int>temp;
            temp.push_back(1);
            long long res = 1;
            for(int j=1;j<i;j++){
                res = res * (i-j);
                res = res/j;
                temp.push_back(res);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};