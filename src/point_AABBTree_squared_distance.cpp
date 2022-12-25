#include "point_AABBTree_squared_distance.h"
#include <queue> // std::priority_queue
#include <iostream>

bool point_AABBTree_squared_distance(
    const Eigen::RowVector3d & query,
    const std::shared_ptr<AABBTree> & root,
    const double min_sqrd,
    const double max_sqrd,
    double & sqrd,
    std::shared_ptr<Object> & descendant)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  
  //The overall equation is from the handout: Breadth-first search 

  //priority queue https://en.cppreference.com/w/cpp/container/priority_queue

  //lambda comparator :  https://www.quora.com/How-can-I-write-this-C++-priority_queue-with-lambda-in-one-line
  auto comp =  [](std::pair<double, std::shared_ptr<Object> > p1, std::pair<double, std::shared_ptr<Object> > p2) 
    {
      return p1.first > p2.first; //so that top will be smallest
  };

  std::priority_queue<std::pair<double, std::shared_ptr<Object> >, std::vector<std::pair<double, std::shared_ptr<Object> > >, decltype(comp) > pq(comp);
  
  double record_min = 99999999;
  pq.push(std::make_pair(point_box_squared_distance(query, root->box), root)); //push the pair of distance of root into the queue as the first one 

  while (!pq.empty()){ //BFS start
  
    std::pair<double, std::shared_ptr<Object> > cur = pq.top(); //current pair with smallest
    pq.pop();

      // std::shared_ptr<AABBTree> casted = std::static_pointer_cast<AABBTree>(cur.second);
      std::shared_ptr<AABBTree> casted = std::dynamic_pointer_cast<AABBTree>(cur.second);
      //https://en.cppreference.com/w/cpp/memory/shared_ptr/pointer_cast
      
      if(!casted){ //if it is the leaf 
        
          if (cur.first >= min_sqrd && cur.first <= max_sqrd && cur.first < record_min){
          sqrd = cur.first;
          descendant = cur.second;
          record_min = cur.first;
          return true; //only no seg fault when put return here :(
          }
        
      }
    
    //will push left and right tree into the pq

      
    else{
      if (casted->left){ //if left subtree not empty
        pq.push(std::make_pair(point_box_squared_distance(query,  casted ->left -> box), casted -> left));}
          //push into queue of left tree
        
          
        if (casted->right){ //if right subtree not empty
        pq.push(std::make_pair(point_box_squared_distance(query, casted->right -> box), casted -> right));}
          //push into queue of right tree
    
    
    }}
    // if (descendant){
    //   sqrd = record_min;
    //   return true; //why can't I call it here
    // }
    
 
  return false;


  
  ////////////////////////////////////////////////////////////////////////////
}

