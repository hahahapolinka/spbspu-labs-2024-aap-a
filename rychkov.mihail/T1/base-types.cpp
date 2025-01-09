#include "base-types.hpp"

#include <cmath>
#include <algorithm>

double rychkov::getDistanceSqr(point_t from, point_t to) noexcept
{
  double deltaX = to.x - from.x;
  double deltaY = to.y - from.y;
  return deltaX * deltaX + deltaY * deltaY;
}
double rychkov::getSquare(point_t p1, point_t p2, point_t p3) noexcept
{
  double side1 = std::sqrt(getDistanceSqr(p1, p2));
  double side2 = std::sqrt(getDistanceSqr(p2, p3));
  double side3 = std::sqrt(getDistanceSqr(p3, p1));
  double semiperimeter = (side1 + side2 + side3) / 2;
  return std::sqrt(semiperimeter * (semiperimeter - side1)
        * (semiperimeter - side2) * (semiperimeter - side3));
}
void rychkov::move(point_t& p1, double deltaX, double deltaY) noexcept
{
  p1.x += deltaX;
  p1.y += deltaY;
}
rychkov::rectangle_t rychkov::makeFrame(point_t bottomLeft, point_t topRight) noexcept
{
  point_t center = {(bottomLeft.x + topRight.x) / 2, (bottomLeft.y + topRight.y) / 2};
  return {topRight.y - bottomLeft.y, topRight.x - bottomLeft.x, center};
}
void rychkov::updateFrame(point_t& bottomLeft, point_t& topRight, point_t newPoint) noexcept
{
  bottomLeft.x = std::min(bottomLeft.x, newPoint.x);
  bottomLeft.y = std::min(bottomLeft.y, newPoint.y);
  topRight.x = std::max(topRight.x, newPoint.x);
  topRight.y = std::max(topRight.y, newPoint.y);
}
