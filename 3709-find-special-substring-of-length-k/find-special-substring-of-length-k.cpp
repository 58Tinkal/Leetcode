

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        if (k > n) return false; 

        for (int i = 0; i <= n - k; i++) {
            char ch = s[i];
            bool isValid = true;
            
            for (int j = i; j < i + k; j++) {
                if (s[j] != ch) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                if ((i > 0 && s[i - 1] == ch) || (i + k < n && s[i + k] == ch)) {
                    isValid = false;
                }
            }
            if (isValid) return true;
        }

        return false;
    }
};

