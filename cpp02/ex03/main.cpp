#include "Point.hpp"
#include "bsp.hpp"

#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

void testBsp(Point const& a, Point const& b, Point const& c, Point const& point, std::string const& description) {
    bool result = bsp(a, b, c, point);
    std::cout << description << ": " << (result ? "Inside" : "Outside") << std::endl;
}

int main() {
    // Definir un triángulo
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    // Casos de prueba
    Point inside1(3, 3);         // Dentro del triángulo
    Point inside2(1, 1);         // Cerca del vértice, pero dentro
    Point outside1(10, 10);      // Fuera del triángulo
    Point outside2(-1, -1);      // Fuera, coordenadas negativas
    Point edge1(5, 0);           // En el borde entre A y B
    Point edge2(0, 5);           // En el borde entre A y C
    Point vertex1(0, 0);         // Exactamente en el vértice A
    Point vertex2(10, 0);        // Exactamente en el vértice B
    Point vertex3(0, 10);        // Exactamente en el vértice C
    Point outside3(6, 6);        // Claramente fuera, pero cerca

    // Pruebas
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
