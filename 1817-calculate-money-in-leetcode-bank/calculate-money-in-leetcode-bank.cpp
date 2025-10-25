class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7 ;
        int ans = weeks * (2 * 28 + (weeks - 1) * 7) / 2;
        ans += days * weeks + days * (days + 1) / 2;
        return ans;
    }
};