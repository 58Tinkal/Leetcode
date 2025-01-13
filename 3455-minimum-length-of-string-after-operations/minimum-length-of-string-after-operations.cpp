class Solution {
public:
    int minimumLength(string s) {
         ios::sync_with_stdio(0); cin.tie(0);
        vector<int>freq(26,0);
        for(auto it:s)  freq[it - 'a']++;
        int ans = 0;
        for(auto it:freq){
            if(it == 0) continue;
            if(it%2 == 0) ans+=2;
            if(it%2 == 1) ans+=1;
        }
        return ans;
    }
};