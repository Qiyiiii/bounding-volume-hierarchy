#include "ray_intersect_triangle_mesh_brute_force.h"
#include "ray_intersect_triangle.h"

bool ray_intersect_triangle_mesh_brute_force(
  const Ray & ray,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double min_t,
  const double max_t,
  double & hit_t,
  int & hit_f)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  hit_t = 0;
  hit_f = 0;
  bool check = false; //record if ever hit
  double  t_min = std::numeric_limits<double>::infinity(); //set closest t to infinity 
  for (int i = 0; i < F.rows();i++){ //loop over each triangle mesh
    Eigen::RowVector3d A = V.row(F(i,0)); //three points that form the triangle
    Eigen::RowVector3d B = V.row(F(i,1));
    Eigen::RowVector3d C = V.row(F(i,2));
    double record_t; //current t
    if (ray_intersect_triangle(ray, A, B, C, min_t, max_t, record_t) ) { //check for intersection
        if (record_t < t_min){
          t_min = record_t;
          hit_f = i;
          check = true;
        }
  }
  if (check != false){ //check if hit
    hit_t = t_min;
    return true;
  }}

  return false;
  ////////////////////////////////////////////////////////////////////////////
}
