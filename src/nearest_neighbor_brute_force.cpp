#include "nearest_neighbor_brute_force.h"
#include <limits>// std::numeric_limits<double>::infinity();

void nearest_neighbor_brute_force(
  const Eigen::MatrixXd & points,
  const Eigen::RowVector3d & query,
  int & I,
  double & sqrD)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  I = -1;
  sqrD = std::numeric_limits<double>::infinity(); //set distance to infi so that we can find shortest
  for (int i=0; i<points.rows(); ++i) { //iterate all points
    Eigen::RowVector3d cur_p = points.row(i);
    double cur_d = (cur_p - query).squaredNorm();  // Squared distance: 
    //https://stackoverflow.com/questions/68789790/squared-euclidean-distance-with-row-major-matrix-eigen-c
    if (cur_d < sqrD) {
      // if shorter dis found, record it
      sqrD = cur_d;
      I = i;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
