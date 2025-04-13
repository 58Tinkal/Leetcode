class Solution {
public:
    string smallestPalindrome(string st) {
        vector<int> f(26, 0);
        for (char c : st) {
            f[c - 'a']++;
        }
        int x = -1;
        for (int i = 0; i < 26; i++) {
            if (f[i] % 2 == 1) {
                x = i;
                break;
            }
        }
        string s = "";
        for (int i = 0; i < 26; i++) {
            if (f[i] > 1) {
                for (int j = 0; j < f[i] / 2; j++) {
                    char ch = (char)('a' + i);
                    s.push_back(ch);
                }
            }
        }
        string str = s;
        reverse(str.begin(), str.end());
        if (x == -1) {
            return s + str;
        }

        char ch = (char)('a' + x);
        s.push_back(ch);

        cout << s << endl;
        return s + str;
    }
};