#include "AABBTree.h"
#include "insert_box_into_box.h"
#include <iostream>
AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth): 
  depth(std::move(a_depth)), 
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //The algorithm comes from page 305, textbook
  int N = objects.size();
  if (N == 1){
    this -> left = objects[0];
    this -> right = nullptr;
    insert_box_into_box(this->left->box, this->box);
  }
  else if (N == 2){
    this -> left = objects[0];
    this->right = objects[1];
    insert_box_into_box(this->left->box, this->box);
    insert_box_into_box(this->right->box, this->box);
  }
  else{
    //finding midpoint of longest axis starting by combine box
    for (int i = 0; i < objects.size(); i++){
      insert_box_into_box(objects[i]->box, this->box);
    }
    int longest = -1;
    double length = -1;
    for(int i = 0; i< 3; i++){ //loop through xyz, longest will be recorded
      double cur_len = this->box.max_corner[i] - this->box.min_corner[i];
      if(cur_len > length){
        length= this->box.max_corner[i] - this->box.min_corner[i];
        longest = i;
    }}

    double m = this->box.center()[longest]; //find the midpoint m of the bounding box of A along AXIS
    //sort object based on longest axis
    //partition A into lists with lengths k and (N − k) surrounding m:
    std::vector<std::shared_ptr<Object> > mleft, mright;
    for (int i = 0; i < objects.size(); i++){
      if (objects[i] -> box.center()[longest] <= m){
        mleft.push_back(objects[i]);
      }
      else{
        mright.push_back(objects[i]);
      }
    }

    std::vector<std::shared_ptr<Object> > sorted;
    //combine vector equation from https://stackoverflow.com/questions/3177241/what-is-the-best-way-to-concatenate-two-vectors
    sorted.reserve( mleft.size() + mright.size() ); // preallocate memory
    sorted.insert( sorted.end(), mleft.begin(), mleft.end() );
    sorted.insert( sorted.end(), mright.begin(), mright.end() );

    auto begin= sorted.begin(); //record start pointer in sorted vector array
    auto mid = sorted.begin() + num_leaves / 2; //record middle pointer
    auto end = sorted.end();//record end pointer

    // this->left = std::make_shared<AABBTree>(mleft, a_depth + 1);
    // this->right = std::make_shared<AABBTree>(mright, a_depth + 1);
    this->left = std::make_shared<AABBTree>(std::vector<std::shared_ptr<Object>>(begin, mid), this->depth + 1);
    this->right = std::make_shared<AABBTree>(std::vector<std::shared_ptr<Object>>(mid, end), this->depth + 1);

    // //bbox = combine(left → bbox, right → bbox)
    // insert_box_into_box(this->left->box, this->box);
    // insert_box_into_box(this->right->box, this->box);
    }

  ////////////////////////////////////////////////////////////////////////////
}


