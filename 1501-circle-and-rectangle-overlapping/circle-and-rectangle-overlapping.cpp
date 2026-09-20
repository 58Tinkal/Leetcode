class Solution {
public:
    bool checkOverlap(int r, int xC, int yC, int x1, int y1, int x2, int y2) {

        // Closest x-coordinate on rectangle
        int closestX = max(x1, min(xC, x2));

        // Closest y-coordinate on rectangle
        int closestY = max(y1, min(yC, y2));

        // Distance between circle center
        // and closest point of rectangle
        long long dx = xC - closestX;
        long long dy = yC - closestY;

        return dx * dx + dy * dy <= 1LL * r * r;
    }
};