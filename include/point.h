#ifndef POINT_H
#define POINT_H

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0);
    bool operator<(const Point& p) const;
    bool operator==(const Point& p) const;
};

#endif // POINT_H
