class Solution {
public:
    set<string>s;
    int n;
    string ans;
    bool solve(int idx,string temp){
        if(idx == n){
            if(s.find(temp) == s.end()){
                ans = temp;
                return true;
            }
            return false;
        }
        return solve(idx+1,temp+"1")||solve(idx+1,temp+"0");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        s = set<string>(nums.begin(),nums.end());
        n = nums[0].size();
        string temp = "";
        if(solve(0,temp)) return ans;
         return " ";
    }
};