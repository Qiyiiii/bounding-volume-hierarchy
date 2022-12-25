#include "box_box_intersect.h"

bool box_box_intersect(
  const BoundingBox & A,
  const BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  //just check if projections to all axes overlap
  //equation comes from https://stackoverflow.com/questions/20925818/algorithm-to-check-if-two-boxes-overlap
  bool check[] = {false, false, false}; //checklists
  for (int i = 0; i < 3; i++){ //loop over each axis
    check[i] = (A.max_corner(i) >= B.min_corner(i) && A.min_corner(i) >= B.max_corner(i));

  }
  for (int i = 0; i<3; i++){
    if (!check[i]){
      return false;
    }
  }
  
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

