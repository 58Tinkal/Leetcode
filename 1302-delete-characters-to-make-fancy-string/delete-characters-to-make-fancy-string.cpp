class Solution {
public:
    string makeFancyString(string s) {
        string str = "";
        int n = s.size();
        int c = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                str.push_back(s[i]);
            else if (s[i] == str.back()) {
                c++;
                if (c < 3)
                    str.push_back(s[i]);
            } else {
                c = 1;
                str.push_back(s[i]);
            }
        }
        return str;
    }
};