class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int n = numBottles;
        int r = 0;
        int ans = 0;
        while (n > 0) {
            ans += n;
            r += n;
            int x = 0;
            while (r >= numExchange) {
                x++;
                r -= numExchange;
                numExchange++;
            }
            n = x;
        }
        return ans;
    }
};