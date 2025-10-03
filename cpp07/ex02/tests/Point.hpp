#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>

struct Point {
	int x, y;
	Point(int a = 0, int b = 0);
};

std::ostream& operator<<(std::ostream& os, const Point& p);
bool operator==(const Point& a, const Point& b);

# endif /* POINT_HPP */