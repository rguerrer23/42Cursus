#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    return (b - a).crossProduct(point - a) >= 0 && (c - b).crossProduct(point - b) >= 0 && (a - c).crossProduct(point - c) >= 0;
}