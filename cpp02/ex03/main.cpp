#include "Point.hpp"
#include "bsp.hpp"

void testBsp(Point const& a, Point const& b, Point const& c, Point const& point, std::string const& description) {
    bool result = bsp(a, b, c, point);
    std::cout << description << ": " << (result ? "Inside" : "Outside") << std::endl;
}

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside1(3, 3);
    Point inside2(1, 1);
    Point outside1(10, 10);
    Point outside2(-1, -1);
    Point edge1(5, 0);
    Point edge2(0, 5);
    Point vertex1(0, 0);
    Point vertex2(10, 0);
    Point vertex3(0, 10);
    Point outside3(6, 6);

    std::cout << "Testing BSP function with different points:" << std::endl;

    testBsp(a, b, c, inside1, "Point (3, 3)");
    testBsp(a, b, c, inside2, "Point (1, 1)");
    testBsp(a, b, c, outside1, "Point (10, 10)");
    testBsp(a, b, c, outside2, "Point (-1, -1)");
    testBsp(a, b, c, edge1, "Point (5, 0) [On edge AB]");
    testBsp(a, b, c, edge2, "Point (0, 5) [On edge AC]");
    testBsp(a, b, c, vertex1, "Point (0, 0) [Vertex A]");
    testBsp(a, b, c, vertex2, "Point (10, 0) [Vertex B]");
    testBsp(a, b, c, vertex3, "Point (0, 10) [Vertex C]");
    testBsp(a, b, c, outside3, "Point (6, 6)");

    return 0;
}
