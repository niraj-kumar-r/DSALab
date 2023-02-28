#ifndef POINTS_H
#define POINTS_H

class Point
{
public:
    Point(int x, int y);
    Point();
    int x;
    int y;
};

class LineSegment
{
public:
    Point P1;
    Point P2;
    LineSegment(Point P1, Point P2);
};

#endif