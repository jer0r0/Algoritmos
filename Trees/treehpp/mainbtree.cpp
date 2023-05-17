#include <iostream>
#include "btree.hpp"

int main(){
  Btree<double> mytree;
  mytree.insert(10);
  mytree.insert(5);
  mytree.insert(13);
  mytree.insert(3);
  mytree.insert(7);
  mytree.insert(12);
  mytree.insert(15);
  mytree.insert(6);
  mytree.insert(11);
  mytree.insert(1);
  mytree.insert(19);
  mytree.insert(9);
  mytree.insert(-2);
  mytree.insert(12.5);


  mytree.display();
  /*
  std::cout << "size: " << mytree.size() << "\n";

  int val = 4;

  if(mytree.contains(val)){
    std::cout << val << " in tree.\n";
  }else{
    std::cout << val << " not in tree.\n";
  }

  std::cout << "min: " << mytree.minimum() << "\n";
  std::cout << "max: " << mytree.maximum() << "\n";
  */

  // mytree.test();
  mytree.remove(13);
  mytree.display();

  
  return 0;
}
