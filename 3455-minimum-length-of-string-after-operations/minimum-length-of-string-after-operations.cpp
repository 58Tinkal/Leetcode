class Solution {
public:
    int minimumLength(string s) {
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