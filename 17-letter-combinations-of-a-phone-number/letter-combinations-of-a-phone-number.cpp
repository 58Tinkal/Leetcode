class Solution {
public:
     vector<string>ans;
     vector<string> comb = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(int idx,string digits,string temp){
         if(idx==digits.size()){
            ans.push_back(temp);
            return;
         }
         for(int i = 0; i < comb[digits[idx]-'0'].size(); i++) {
            temp.push_back(comb[digits[idx]-'0'][i]);
            solve(idx+1, digits, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       if (digits.length() == 0) {
            return ans;
        }
        string temp = "";
        solve(0,digits,temp);
        return ans;
    }
};