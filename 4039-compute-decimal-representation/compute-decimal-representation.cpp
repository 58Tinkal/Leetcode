class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        string s = to_string(n);
        int m = s.size();
        long long x = 1;
        vector<int> ans;
        for (int i = m - 1; i >= 0; i--) {
            int val = (s[i] - '0') * x;
            x = x * 10;
            if (val > 0)
                ans.push_back((int)val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};