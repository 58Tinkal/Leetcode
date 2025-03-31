class Solution {
public:
    int reverseDegree(string s) {
        int su = 0;
        int i = 1;
        for (auto& it : s) {
            su += (26 - (it - 'a')) * i;
            i++;
        }
        return su;
    }
};