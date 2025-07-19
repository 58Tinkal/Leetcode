class Solution {
public:
    bool isPrefix(const string& prefix, const string& str) {
        return str.compare(0, prefix.length(), prefix) == 0;
    }

    vector<string> removeSubfolders(vector<string>& f) {
        int n = f.size();
        sort(f.begin(), f.end());
        string s = f[0];
        vector<string> ans;
        ans.push_back(s);

        for (int i = 1; i < n; i++) {
            bool is_pref = isPrefix(s + "/", f[i]);
            if (is_pref)
                continue;
            s = f[i];
            ans.push_back(s);
        }
        return ans;
    }
};
