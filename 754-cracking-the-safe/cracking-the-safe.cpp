class Solution {
public:
    int total;
    int n, k;
    unordered_set<string> seen; 
    string result;
    bool found = false;

    void dfs(string cur) {
        if (found) return; 

       
        string node = cur.substr(cur.size() - n);  
        if (seen.count(node)) return;

        seen.insert(node);

        if ((int)seen.size() == total) {
            result = cur;
            found = true;
            return;
        }

        for (int c = 0; c < k; c++) {
            dfs(cur + char('0' + c));
            if (found) return;
        }

        seen.erase(node);
    }

    string crackSafe(int n, int k) {
       this->n = n;
       this->k = k;
        total = pow(k, n);
        seen.clear();
        result = "";
        found = false;

        string start(n, '0');  
        dfs(start);
        return result;
    }
};
