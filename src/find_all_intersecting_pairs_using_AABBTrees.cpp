#include "find_all_intersecting_pairs_using_AABBTrees.h"
#include "box_box_intersect.h"
// Hint: use a list as a queue
#include <list> 

void find_all_intersecting_pairs_using_AABBTrees(
  const std::shared_ptr<AABBTree> & rootA,
  const std::shared_ptr<AABBTree> & rootB,
  std::vector<std::pair<std::shared_ptr<Object>,std::shared_ptr<Object> > > & 
    leaf_pairs)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //equation comes from BVH Intersection Queries in slides
  leaf_pairs = {};
  std::list<std::pair<std::shared_ptr<Object>, std::shared_ptr<Object> > > Q;
  if (box_box_intersect(rootA->box, rootB->box)) {
    Q.push_back(std::make_pair(rootA, rootB));
  }
  while (!Q.empty()){
    std::pair<std::shared_ptr<Object>, std::shared_ptr<Object> > p = Q.front(); //first come first out
    std::shared_ptr<Object> node1 = p.first;
    std::shared_ptr<Object> node2 = p.second;
    Q.pop_front();

    std::shared_ptr<AABBTree> n1 = std::dynamic_pointer_cast<AABBTree>(node1);
    std::shared_ptr<AABBTree> n2 = std::dynamic_pointer_cast<AABBTree>(node2);

    if (!n1 && !n2){ // both leaf
      leaf_pairs.push_back(std::make_pair(n1,n2));
    }
    else if (!node1){ //node1 leaf
      if (n2->left && box_box_intersect(n1->box, n2-> left -> box)){
        Q.push_back(std::make_pair(n1, n2->left));
      }
      if (n2->right && box_box_intersect(n1->box, n2-> right -> box)){
        Q.push_back(std::make_pair(n1, n2->right));
    }}
    else if (!node2){ //node2 leaf
      if (n1->left && box_box_intersect(n2->box, n1-> left -> box)){
        Q.push_back(std::make_pair(n2, n1->left));
      }
      if (n1->right && box_box_intersect(n2->box, n1-> right -> box)){
        Q.push_back(std::make_pair(n2, n1->right));
    }}
    else{ //both are not leaf
      if (n2->left && box_box_intersect(n1->box, n2-> left -> box)){
        Q.push_back(std::make_pair(n1, n2->left));
      }
      if (n2->right && box_box_intersect(n1->box, n2-> right -> box)){
        Q.push_back(std::make_pair(n1, n2->right));
    }
    if (n1->left && box_box_intersect(n2->box, n1-> left -> box)){
        Q.push_back(std::make_pair(n2, n1->left));
      }
      if (n1->right && box_box_intersect(n2->box, n1-> right -> box)){
        Q.push_back(std::make_pair(n2, n1->right));
    }}

    }


  ////////////////////////////////////////////////////////////////////////////
}
