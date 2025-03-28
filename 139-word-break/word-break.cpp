class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> seen(s.size(), false);
        q.push(0);
        while (!q.empty()) {
            int st = q.front();
            q.pop();
            if (st == s.size()) {
                return true;
            }
            for (int i = st + 1; i <= s.size(); i++) {
                if (seen[i]) {
                    continue;
                }
                if (word.find(s.substr(st, i - st)) != word.end()) {
                    q.push(i);
                    seen[i] = true;
                }
            }
        }
        return false;
    }
};