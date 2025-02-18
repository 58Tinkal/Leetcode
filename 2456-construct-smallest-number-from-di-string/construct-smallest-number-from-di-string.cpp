class Solution {
public:
    string ans = "";
    vector<bool> vis; // To track used digits

    void solve(string &p, string s, int idx) {
        if (idx == p.size()) { 
            if (ans.empty() || s < ans) ans = s;
            return;
        }

        int lastDigit = s.back() - '0'; 

        if (p[idx] == 'I') {
            for (int d = lastDigit + 1; d <= 9; d++) { 
                if (!vis[d]) {
                    vis[d] = true;
                    solve(p, s + char(d + '0'), idx + 1);
                    vis[d] = false; 
                }
            }
        } else { 
            for (int d = lastDigit - 1; d >= 1; d--) { 
                if (!vis[d]) {
                    vis[d] = true;
                    solve(p, s + char(d + '0'), idx + 1);
                    vis[d] = false; 
                }
            }
        }
    }

    string smallestNumber(string p) {
        ans = "";
        vis.assign(10, false); 
        for (int d = 1; d <= 9; d++) { 
            vis[d] = true;
            solve(p, string(1, char(d + '0')), 0);
            vis[d] = false;
        }
        return ans;
    }
};
