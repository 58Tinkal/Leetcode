class Solution {
public:
    bool isValid(string &s,int pos,int sum,int &val){
        if(pos >= s.size()) return sum == val;

        for(int i=0;i+pos<s.size();i++){
            int curr_val = stoi(s.substr(pos,i+1));
            if(isValid(s,i+pos+1,sum+curr_val,val)){
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 1;
        for(int i=2;i<=n;i++){
            string s = to_string(i*i);
            if(isValid(s,0,0,i)){
                ans += i*i;
            }
        }
        return ans;
    }
};