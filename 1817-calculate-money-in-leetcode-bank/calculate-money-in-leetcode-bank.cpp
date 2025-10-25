class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int prevMon = 1;
        while (n > 0) {
            int x = prevMon;
            for (int i = 0; i < min(7, n); i++) {
                ans += x;
                x++;
            }
            prevMon++;
            n -= 7;
        }
        return ans;
    }
};