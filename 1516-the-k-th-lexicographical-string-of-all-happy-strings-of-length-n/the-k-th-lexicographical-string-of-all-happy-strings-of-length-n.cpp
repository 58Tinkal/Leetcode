class Solution {
public:
    vector<string> ans;
    
    void solve(int idx, int n, string s, char last) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ++ch) {
            if (ch != last) {  
                s.push_back(ch);
                solve(idx + 1, n, s, ch);
                s.pop_back(); 
            }
        }
    }

    string getHappyString(int n, int k) {
        solve(0, n, "", '*');  
        
        if (k > ans.size()) return "";  
        
        return ans[k - 1];  
    }
};
