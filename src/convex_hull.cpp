#include "convex_hull.h"
#include <algorithm>
#include <stack>

int ConvexHull::orientation(const Point& p, const Point& q, const Point& r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int ConvexHull::distanceSquared(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

std::vector<Point> ConvexHull::grahamScan(std::vector<Point>& points) {
    int n = points.size();
    std::vector<Point> hull;

    if (n < 3) return hull;

    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y, min = i;
        }
    }
    std::swap(points[0], points[min]);

    Point p0 = points[0];
    std::sort(points.begin() + 1, points.end(), [p0](Point p1, Point p2) {
        int o = ConvexHull::orientation(p0, p1, p2);
        if (o == 0)
            return ConvexHull::distanceSquared(p0, p2) >= ConvexHull::distanceSquared(p0, p1);
        return o == 2;
    });

    std::vector<Point> temp;
    temp.push_back(points[0]);
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && ConvexHull::orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        temp.push_back(points[i]);
    }

    if (temp.size() < 3) return hull;

    std::stack<Point> s;
    s.push(temp[0]);
    s.push(temp[1]);
    s.push(temp[2]);

    for (int i = 3; i < temp.size(); i++) {
        while (s.size() > 1) {
            Point top = s.top();
            s.pop();
            Point next_to_top = s.top();
            if (ConvexHull::orientation(next_to_top, top, temp[i]) != 2) {
                continue;
            } else {
                s.push(top);
                break;
            }
        }
        s.push(temp[i]);
    }

    while (!s.empty()) {
        hull.push_back(s.top());
        s.pop();
    }

    std::reverse(hull.begin(), hull.end());
    return hull;
}