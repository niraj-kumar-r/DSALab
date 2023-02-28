#include "points.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

LineSegment::LineSegment(Point P1, Point P2)
{
    this->P1 = P1;
    this->P2 = P2;
}
