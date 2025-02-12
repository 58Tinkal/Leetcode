class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        for(auto it:nums){
            int s = 0;
            int x = it;
            while(x>0){
                int d = x%10;
                s+=d;
                x = x/10;
            }
            m[s].push_back(it);
        }
        int ans = INT_MIN;
        for(auto it:m){
            vector<int>v = it.second;
            sort(v.begin(),v.end(),greater<int>());
            if(v.size() < 2) continue;
            ans = max(ans,v[0]+v[1]);
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};