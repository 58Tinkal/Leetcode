class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++){
                m[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto it:m){
            int x = it.second;
            x--;
            ans += (x*(x+1)/2)*8;
        }
        return ans;
    }
};