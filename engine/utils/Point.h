#ifndef POINT_H
#define POINT_H

struct Point {
    constexpr Point(const int x, const int y) : x(x), y(y) { }

    const int x;
    const int y;
};

#endif
