class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a'] = i;
        }
        int st = 0, e = 0;
        for (int i = 0; i < n; i++) {
            e = max(e, freq[s[i] - 'a']);
            if (e == i) {
                ans.push_back(e - st + 1);
                st = i + 1;
            }
        }
        return ans;
    }
};