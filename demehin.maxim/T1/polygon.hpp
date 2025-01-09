#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <cstddef>
#include "shape.hpp"

namespace demehin
{
  class Polygon final: public Shape
  {
  public:
    Polygon(size_t vrtx_cnt, const point_t* vertex);
    ~Polygon();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
    void setVertex(const point_t* vertex, size_t vrt_cnt);
    point_t getCenter() const;
  private:
    size_t vrtx_cnt_;
    point_t* vertex_;
  };
}

#endif
