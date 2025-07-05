class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>freq(505,0);
        for(auto &it:arr){
            freq[it]++;
        }
        int ans = -1;
        for(int i=1;i<=500;i++){
            if(freq[i] == i){
               ans = i;
            }
        }
        return ans;
    }
};