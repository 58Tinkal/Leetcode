class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n = numBottles;
        int e = numExchange;
        int drink = 0;
        int r = 0;
        while (n > 0) {
            drink += n;
            r += n;
            n = r/e;
            r = r%e;
        }
        return drink;
    }
};