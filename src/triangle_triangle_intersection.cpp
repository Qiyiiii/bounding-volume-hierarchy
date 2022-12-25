#include "ray_intersect_triangle.h"
#include "triangle_triangle_intersection.h"


bool triangle_triangle_intersection(
  const Eigen::RowVector3d & A0,
  const Eigen::RowVector3d & A1,
  const Eigen::RowVector3d & A2,
  const Eigen::RowVector3d & B0,
  const Eigen::RowVector3d & B1,
  const Eigen::RowVector3d & B2)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  //equation comes from Triangle Triangle intersection in the slide

  //algorithm 1:

  //first, consider three sides of triangle as ray, and test if each of them intersect with the other triangle
  //see if  at least one tri edge intersects the other tri.

  Ray ray(Eigen::Vector3d(-1, -1, -1), Eigen::Vector3d(-1, -1, -1)); //init a ray
  double min_t = 0;
  double max_t = 99999;
  double t; 

  //line A1A0
  ray.origin = A0;
  ray.direction = A1 - A0;
  if (ray_intersect_triangle(ray, B0, B1, B2, min_t, max_t ,t))
        return true;

  //line A2A1
  ray.origin = A1;
  ray.direction = A2 - A1;
  if (ray_intersect_triangle(ray, B0, B1, B2, min_t, max_t ,t))
        return true;

  //line A2A0
  ray.origin = A0;
  ray.direction = A2 - A0;
  if (ray_intersect_triangle(ray, B0, B1, B2, min_t, max_t ,t))
        return true;

  //consider 3 sides of B as ray
    //line B1B0
  ray.origin = B0;
  ray.direction = B1 - B0;
  if (ray_intersect_triangle(ray, B0, B1, B2, min_t, max_t ,t))
        return true;

  //line B2B1
  ray.origin = B1;
  ray.direction = B2 - B1;
  if (ray_intersect_triangle(ray, B0, B1, B2, min_t, max_t ,t))
        return true;

  //line B2A0
  ray.origin = B0;
  ray.direction = B2 - B0;
  if (ray_intersect_triangle(ray, B0, B1, B2, min_t, max_t ,t))
        return true;



  return false; //if no intersection occured
  ////////////////////////////////////////////////////////////////////////////
}
