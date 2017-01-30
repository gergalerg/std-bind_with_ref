#include "test.h"

bool Circle::intersect(const Shape& s) const { return s.intersect(*this); }
bool Circle::intersect(const Circle&) const { std::cout << "intersect(circle, circle)\n"; return true;}
bool Circle::intersect(const Triangle&) const { std::cout << "intersect(circle, triangle)\n"; return false; }

bool Triangle::intersect(const Shape& s) const { return s.intersect(*this); }
bool Triangle::intersect(const Circle&) const { std::cout << "intersect(triangle, circle)\n"; return false; }
bool Triangle::intersect(const Triangle&) const { std::cout << "intersect(triangle, triangle)\n"; return true; }