class Solution {
public:
    int countSubseq(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        int c = 0;
        while (i < n) {
            if (s[i] == t[j]) {
                j++;
                if (j == m) {
                    j = 0;
                    c++;
                }
            }
            i++;
        }
        return c;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (auto& it : s) {
            freq[it - 'a']++;
        }
        string cur = "";
        queue<string> q;
        q.push(cur);
        string res = cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            string next = cur;
            for (char c = 'a'; c <= 'z'; c++) {
                if (freq[c - 'a'] < k)
                    continue;

                next.push_back(c);
                if (countSubseq(s, next) >= k) {
                    res = next;
                    q.push(next);
                }
                next.pop_back();
            }
        }
        return res;
    }
};