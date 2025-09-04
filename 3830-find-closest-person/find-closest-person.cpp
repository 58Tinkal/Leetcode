class Solution {
public:
    int findClosest(int x, int y, int z) {
        int X = abs(z - x);
        int Y = abs(z - y);
        if (X == Y)
            return 0;
        if (X > Y)
            return 2;
        return 1;
    }
};