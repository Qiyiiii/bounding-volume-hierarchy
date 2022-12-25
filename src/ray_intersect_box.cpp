#include "ray_intersect_box.h"
#include <iostream>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:


  // I will use Ray-AABB intersection equation from the slide
  double x_min = box.min_corner(0);
  double x_max = box.max_corner(0);
  double y_min = box.min_corner(1);
  double y_max = box.max_corner(1);
  double z_min = box.min_corner(2);
  double z_max = box.max_corner(2);
  //ray origin
  double xe = ray.origin(0);
  double ye = ray.origin(1);
  double ze = ray.origin(2);
  //ray direction
  double xd = ray.direction(0);
  double yd = ray.direction(1);
  double zd = ray.direction(2);

  double txmin, txmax,tymin,tymax,tzmin,tzmax;

  if (xd > 0){ //note that if direction of ray is negative, then min and max t will be flipped
    //reference equation in pg 300, textbook
    double txmin = (x_min-xe)/xd;
    double txmax = (x_max-xe)/xd;
  }
  else{
    double txmin = (x_max-xe)/xd;
    double txmax = (x_min-xe)/xd;
  }

  if (yd > 0){
    double tymin = (y_min-ye)/yd;
    double tymax = (y_max-ye)/yd;
  }
  else{
    double tymin = (y_max-ye)/yd;
    double tymax = (y_min-ye)/yd;
  }

  if (zd > 0){
    double tzmin = (z_min-ze)/zd;
    double tzmax = (z_max-ze)/zd;
  }
  else{
    double tzmin = (z_max-ze)/zd;
    double tzmax = (z_min-ze)/zd;
  }

  double t_min = std::max(std::max(txmin, tymin), tzmin); //record as max(txmin, tymin, tzmin)
  double t_max = std::min(std::min(txmax, tymax), tzmax); //record as min(txmax, tymax, tzmax)

  if (t_max < t_min){ //check if in box
    return false;
  }
  if (t_min > max_t && t_max < min_t){ // check if outside min_t or max_t
    return false;
  }
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
