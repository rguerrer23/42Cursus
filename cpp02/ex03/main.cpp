#include "Point.hpp"
#include "bsp.hpp"

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(3, 3);
    Point outside(10, 10);
    Point onEdge(5, 0);

    std::cout << "Point inside: " << (bsp(a, b, c, inside) ? "True" : "False") << std::endl;
    std::cout << "Point outside: " << (bsp(a, b, c, outside) ? "True" : "False") << std::endl;
    std::cout << "Point on edge: " << (bsp(a, b, c, onEdge) ? "True" : "False") << std::endl;

    return 0;
}
