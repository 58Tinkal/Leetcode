class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
        stack<int> unlocked, openBracket;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                unlocked.push(i);
            } else if (s[i] == '(') {
                openBracket.push(i);
            } else if (s[i] == ')') {
                if (!openBracket.empty()) {
                    openBracket.pop();
                } else if (!unlocked.empty()) {
                    unlocked.pop();
                }else return false;
            } 
        }
        while (!unlocked.empty() && !openBracket.empty() &&
               openBracket.top() < unlocked.top()) {
            openBracket.pop();
            unlocked.pop();
        }
        if (!openBracket.empty() ) {
            return false;
        }
        return true;
    }
};