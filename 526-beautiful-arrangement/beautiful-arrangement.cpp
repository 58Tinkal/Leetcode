class Solution {
public:
    void solve(int idx,int & ans, vector<int>&a){
        if(idx == a.size()){
            ans++;
            return;
        }
        for(int i=idx;i<a.size();i++){
            swap(a[idx],a[i]);
            if(a[idx]%(idx+1)==0 || (idx+1)%a[idx] == 0){
                solve(idx+1,ans,a);
            }
            swap(a[idx],a[i]);
        }
    }
    int countArrangement(int n) {
        int ans = 0;
        vector<int>a;
        for(int i=1;i<=n;i++){
            a.push_back(i);
        }
        solve(0,ans,a);
        return ans;
    }
};