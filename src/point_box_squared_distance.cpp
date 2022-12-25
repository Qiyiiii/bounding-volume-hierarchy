#include "point_box_squared_distance.h"

double point_box_squared_distance(
  const Eigen::RowVector3d & query,
  const BoundingBox & box)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  double total = 0;
  for (int i=0; i<3; ++i) {
    double r = 0;
    if (query[i] > box.max_corner(i)){ //if query(i) out of bound, then find difference as distance on the axis
      r += query[i] - box.max_corner(i);
    }
    else if (query[i] < box.min_corner(i)){
      r += box.min_corner(i) - query(i);
    }
    else{  //if one of query(i)'s axis is in the box, then distance on that axis from box is 0
      r += 0;
    }
    total += r * r;
  }
  
  return total;
  ////////////////////////////////////////////////////////////////////////////
}
