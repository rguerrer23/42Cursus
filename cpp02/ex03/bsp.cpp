#include "bsp.hpp"

static Fixed calculateArea(Point const &a, Point const &b, Point const &c)
{
	return Fixed((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = calculateArea(a, b, c).toFloat();
	if (totalArea < 0)
		totalArea = -totalArea;
	
	Fixed area1 = calculateArea(a, b, point).toFloat();
	if (area1 < 0)
		area1 = -area1;
	
	Fixed area2 = calculateArea(a, point, c).toFloat();
	if (area2 < 0)
		area2 = -area2;
	
	Fixed area3 = calculateArea(point, b, c).toFloat();
	if (area3 < 0)
		area3 = -area3;
	
	if (totalArea == 0 || area1 == 0 || area2 == 0 || area3 == 0)
		return 0;
	return (totalArea == area1 + area2 + area3);
}