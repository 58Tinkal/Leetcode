class Solution {
public:
    void dfs(int cur, int &n, vector<int>& res) {
        if (cur > n) return;  
        res.push_back(cur);   
        for (int i = 0; i <= 9; i++) {
            int next = cur * 10 + i; 
            if (next > n) break;     
            dfs(next, n, res);       
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) { 
            dfs(i, n, res);
        }
        return res;
    }
};
