class Solution {
public:
    vector<string>ans;
    void solve(int op, int cl, string &s){
          if(op==0&&cl==0){
            ans.push_back(s);
            return;
          }

        if(op>0){
            s.push_back('(');
            solve(op-1,cl,s);
            s.pop_back();
        }
        if(cl>0){
            if(cl>op){
                s.push_back(')');
                solve(op,cl-1,s);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(n,n,s);
        return ans;
    }
};