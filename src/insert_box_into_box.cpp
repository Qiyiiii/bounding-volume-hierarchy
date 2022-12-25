#include "insert_box_into_box.h"
#include <iostream>
void insert_box_into_box(
  const BoundingBox & A,
  BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //I will simply modify B box with minimum xmin,ymin and zmin as well as maximum xmax, ymax and zmax value out of A and B boxes
  
  B.min_corner(0) = std::min(A.min_corner(0), B.min_corner(0)); //x-value
  B.max_corner(0) = std::max(A.max_corner(0), B.max_corner(0));

  B.min_corner(1) = std::min(A.min_corner(1), B.min_corner(1)); //y-value
  B.max_corner(1) = std::max(A.max_corner(1), B.max_corner(1));

  B.min_corner(2) = std::min(A.min_corner(2), B.min_corner(2)); //z-value
  B.max_corner(2) = std::max(A.max_corner(2), B.max_corner(2));
  ////////////////////////////////////////////////////////////////////////////
}

