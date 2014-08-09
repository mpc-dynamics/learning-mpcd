#include <iostream>
#include "vect2.h"

int main(){
  vect2 * v1 = new vect2(10, 10);
  vect2 * v2 = new vect2(20, 20);
  std::cout << v1->str() << std::endl;
  v1->add(v2)->sub(v2)->rotate(30)->mult(3);
  v1->print();
  std::cout << "cross: " << v1->cross(v2) << std::endl;
  std::cout << "dot: " << v1->dot(v2) << std::endl;
  delete v1;
  delete v2;
}