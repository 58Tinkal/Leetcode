class Solution {
public:
    int minMaxDifference(int num) {
        string s1 = to_string(num);
        string s2 = to_string(num);
        char c1, c2;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != '9') {
                c1 = s1[i];
                s1[i] = '9';
                break;
            }
        }
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == c1) {
                s1[i] = '9';
            }
        }
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] != '0') {
                c2 = s2[i];
                s2[i] = '0';
                break;
            }
        }
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == c2) {
                s2[i] = '0';
            }
        }
        int x = stoi(s1);
        int y = stoi(s2);
        return x - y;
    }
};