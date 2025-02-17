class Solution {
public:
    int solve(vector<int>&freq){
        int x = 0;
        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            freq[i]--;
            x += 1+solve(freq);
            freq[i]++;
        }
        return x;
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26);
        for(auto &it:tiles){
            freq[it-'A']++;
        }
        return solve(freq);
    }
};