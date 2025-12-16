class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;
        for (auto& it : s) {
            if (it == '(') {
                mn += 1;
                mx += 1;
            } else if (it == ')') {
                mx -= 1;
                mn -= 1;
            } else {
                mn -= 1;
                mx += 1;
            }
            if (mn < 0)
                mn = 0;
            if (mx < 0)
                return false;
        }
        if (mn == 0)
            return true;
        return false;
    }
};