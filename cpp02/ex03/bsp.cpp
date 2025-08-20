#include "Point.hpp"

//  Area = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| 
int get_triangle_area(Point const a, Point const b, Point const c)
{
	return (ABS(
		(a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY())
		+ c.getX() * (a.getY() - b.getY())).getRawBits()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int fullABC = get_triangle_area(a, b, c);
	int areaABP = get_triangle_area(a, b, point);
	int areaBCP = get_triangle_area(b, c, point);
	int areaACP = get_triangle_area(a, c, point);
	if (areaABP == 0 || areaBCP == 0 || areaACP == 0)
		return (false);
	return (fullABC == areaABP + areaBCP + areaACP);
}
