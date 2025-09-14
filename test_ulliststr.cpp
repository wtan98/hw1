#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std; 

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list; 
  list.push_back("A");
  list.push_front("B");
  list.push_back("C");
  list.push_back("X");
  list.push_front("Y");
  list.push_back("Z");

  for (size_t i =0; i < list.size(); i++){
    cout << list.get((i)) << " ";
  }
  cout << endl; 

  cout << "will remove back" << endl; 
  list.pop_back(); 

  cout << "back: " << list.back() << "front: " << list.front() << endl; 
  cout << "will remove front" << endl; 
  list.pop_front(); 

  cout << "item at index 0 (front): " << list.get(0) << endl; 

  return 0; 
}
