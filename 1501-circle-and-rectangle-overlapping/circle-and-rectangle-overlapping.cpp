class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int XClosest = max(x1 , min(xCenter , x2));
        int YClosest = max(y1 , min(yCenter , y2));

        int dx = xCenter - XClosest;
        int dy = yCenter - YClosest;

        int distance = dx*dx + dy*dy;

        return distance <= radius*radius;
    }
};