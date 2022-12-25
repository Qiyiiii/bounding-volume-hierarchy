#include "ray_intersect_triangle.h"
#include <Eigen/Dense>
#include <iostream>
bool ray_intersect_triangle(
  const Ray & ray,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  const double min_t,
  const double max_t,
  double & t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  //copied and paste from A2
  Eigen::Vector3d t1, t2;
  t1 = A - B;
  t2 = C - B;
  Eigen::Vector3d n;
  n = -(t1.cross(t2)).normalized();

  Eigen::Matrix3d mat;
  mat << t1, t2, -ray.direction;
  mat.transpose();
  Eigen::Vector3d ABt = mat.inverse() * (ray.origin - (Eigen::Vector3d) B); //A,B,t = <t1, t2, -d).inverse * (e-offset)

	double alpha = ABt[0];
	double beta = ABt[1];
	//   std::cout << alpha <<" ";
  t = (ABt[2]);
  if (alpha >= 0 && beta >= 0 && alpha+beta <= 1 && t >= min_t && t < max_t){
	  return true;
  }
  else{
	  return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}

