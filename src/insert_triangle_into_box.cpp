#include "insert_triangle_into_box.h"

void insert_triangle_into_box(
  const Eigen::RowVector3d & a,
  const Eigen::RowVector3d & b,
  const Eigen::RowVector3d & c,
  BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //we will consider about 3 point and original box dimension to compute minimum and maximum

  //smallest & largest x value
  B.min_corner(0) = std::min(B.min_corner(0), std::min(a(0), std::min(b(0),c(0))));
  B.max_corner(0) = std::max(B.min_corner(0), std::max(a(0), std::max(b(0),c(0))));
  //smallest & largest y value
  B.min_corner(1) = std::min(B.min_corner(1), std::min(a(1), std::min(b(1),c(1))));
  B.max_corner(1) = std::max(B.min_corner(1), std::max(a(1), std::max(b(1),c(1))));
  //smallest & largest z value
  B.min_corner(2) = std::min(B.min_corner(2), std::min(a(2), std::min(b(2),c(2))));
  B.max_corner(2) = std::max(B.min_corner(2), std::max(a(2), std::max(b(2),c(2))));
  ////////////////////////////////////////////////////////////////////////////
}


