class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& c, int t, int sum,vector<int>&temp,int s){
        if(sum>t) return;
        if(sum == t) {
            ans.push_back(temp);
            return;
        }
        for(int i=s;i<c.size();i++){
            if(sum+c[i]>t) continue;
            temp.push_back(c[i]);
            solve(c,t,sum+c[i],temp,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<int>temp;
        solve(c,t,0,temp,0);
        return ans;
    }
};