class Solution {
public:
    vector<string> ans;

    bool check(string s) {
        if (s.size() > 3 || s.empty()) return false;
        if (s.size() > 1 && s[0] == '0') return false; 
        int num = stoi(s);
        if (num > 255) return false;
        return true;
    }

    void solve(int idx, int dot, string temp, string& s) {
        if (dot == 3) { 
            string lastSegment = s.substr(idx);
            if (check(lastSegment)) {
                ans.push_back(temp + lastSegment);
            }
            return;
        }

        for (int i = idx; i < min(idx + 3, (int)s.size()); i++) {
            string segment = s.substr(idx, i - idx + 1);
            if (check(segment)) {
                solve(i + 1, dot + 1, temp + segment + ".", s);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return ans;
        solve(0, 0, "", s);
        return ans;
    }
};
