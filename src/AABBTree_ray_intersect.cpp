#include "AABBTree.h"

// See AABBTree.h for API
bool AABBTree::ray_intersect(
  const Ray& ray,
  const double min_t,
  const double max_t,
  double & t,
  std::shared_ptr<Object> & descendant) const 
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  //equation modified from  pg302, textbook
  t = 0;

  if (ray_intersect_box(ray, this->box, min_t,max_t)){
    //if (ray hits root box) then
    double lt ,rt, t1;
    
    std::shared_ptr<Object> ld = this->left;
     std::shared_ptr<Object> rd = this->right;
  
    // double cur_t = 9999999; 
    // std::shared_ptr<Object> cur_des;
    //record result of two hit from left and right subtree
    bool leftT = this->left && this->left->ray_intersect(ray, min_t, max_t, lt, ld);
    bool rightT = this -> right && this->right->ray_intersect(ray, min_t, max_t, rt, rd);
   
    if (leftT&&rightT){ //if ray hit both children
      if (lt > rt){ //if better t in right
          t = rt;
          descendant = rd;
        }
      else{ //if lt is better
          t= lt;
          descendant = ld;
      }
      return true;
    }
    else if (leftT){ //if only hit left box
      t= lt;
      descendant = ld;
      return true;
    }
    else if (rightT){ //if only hit right box
      t = rt;
      descendant = rd;
      return true;
    }
    else{
      return false;
    }}

    
    // if (this->left && this->left->ray_intersect(ray, min_t, max_t, lt, ld)){
    //   //if (ray hits left subtree box) then:
    //   cur_t = lt;
    //   cur_des = ld;}
    
    // if (this->right && this->right->ray_intersect(ray, min_t, max_t, rt, rd)){
    //   //if (ray hits right subtree box) then:
    //   if (cur_t != 9999999){ //if (ray also hits left subtree box)
    //     if (cur_t > rt){ //if better t in right
    //       cur_t = rt;
    //       cur_des = rd;
    //     }
    //     }
    //     else{ //if not hits right subtree box
    //       cur_t = rt;
    //       cur_des = rd;
    //     }

    //   }
    


  return false; //if not hit anything
  ////////////////////////////////////////////////////////////////////////////
}

