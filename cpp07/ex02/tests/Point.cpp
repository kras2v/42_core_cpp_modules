#include "Point.hpp"

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

bool operator==(const Point& a, const Point& b) {
	return a.x == b.x && a.y == b.y;
}

Point::Point(int a, int b) : x(a), y(b) {}