#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

#include <vector>
#include "point.h"

class ConvexHull {
public:
    static std::vector<Point> grahamScan(std::vector<Point>& points);
private:
    static int orientation(const Point& p, const Point& q, const Point& r);
    static int distanceSquared(const Point& p1, const Point& p2);
};

#endif // CONVEX_HULL_H
