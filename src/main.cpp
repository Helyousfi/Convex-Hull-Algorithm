#include <iostream>
#include "point.h"
#include "convex_hull.h"

int main() {
    std::vector<Point> points = { {0, 3}, {1, 1}, {2, 2}, {4, 4},
                                  {0, 0}, {1, 2}, {3, 1}, {3, 3} };
    std::vector<Point> hull = ConvexHull::grahamScan(points);

    std::cout << "Points in the Convex Hull:\n";
    for (const auto& point : hull) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
