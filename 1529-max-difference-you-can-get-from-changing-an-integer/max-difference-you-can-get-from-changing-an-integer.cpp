class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxNum = s, minNum = s;


        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax) {
            for (char &c : maxNum) {
                if (c == toReplaceMax) c = '9';
            }
        }

        char toReplaceMin = 0;
        if (s[0] != '1') {
            toReplaceMin = s[0];
            for (char &c : minNum) {
                if (c == toReplaceMin) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    for (int j = 1; j < s.size(); ++j) {
                        if (minNum[j] == toReplaceMin) minNum[j] = '0';
                    }
                    break;
                }
            }
        }

        int a = stoi(maxNum);
        int b = stoi(minNum);
        return a - b;
    }
};
