class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        int n = s.size();
        vector<vector<int>>pos(26);
        for(int i=0;i<s.size();i++){
            pos[s[i] - 'a'].push_back(i);
        }
        vector<bool>isfirst(n,false);
        vector<int>dp(n+1,0);
         for (int i = 0; i < 26; i++) {
            if (!pos[i].empty()) {
                isfirst[pos[i][0]] = true;  
            }
        }
        for(int i=n-1;i>=0;i--){
            if(isfirst[i]){
                int j = i;
                int m = pos[s[i] - 'a'].back();
                bool f = true;
                while(j<m){
                    j++;
                    m = max(m,pos[s[j] - 'a'].back());
                    if(pos[s[j] - 'a'][0] < i){
                        f = false;
                        break;
                    }
                }
                if(f && !(i == 0 && j == n-1)){
                    dp[i] = 1 + dp[j+1];
                }
            }
            dp[i] = max(dp[i],dp[i+1]);
        }
        if(dp[0] >= k) return true;
        return false;
    }
};