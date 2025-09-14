/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"
using namespace std; 

int main(int argc, char* argv[])
{
  int n = 0, val = 0;
  Node* head = nullptr;
  Node* tail = nullptr;

  cout << "Enter number of integers in your list: " << endl; 
  cin >> n; 

  cout << "Enter your list: " << endl;   
  for (int i = 0; i < n; i++){
    cin >> val; 

    //make a new node to sure first entered val
    Node* newNode = new Node(val, nullptr); 
    //newNode->value = val;
    //newNode->next = nullptr; 

    //check if list is empty, else add value to end of list 
    if (head == nullptr){
      head = newNode; 
      tail = newNode;
    }
    else{
      tail->next = newNode; 
      tail = newNode; 
    }
  }

  //run the actual program to split
  Node* oddVals = nullptr; 
  Node* evenVals = nullptr; 
  split(head, oddVals, evenVals);
 
  //now that its split, assign curr to the odds first
  Node* curr = oddVals; 

  //print out all the odds 
  cout<< "Odds: ";
  while (curr){
    cout << curr->value << " "; 
    //move to the next odd
    Node* temp = curr; 
    curr = curr->next; 
    delete temp; 
  }
  cout <<endl; 

  //now print all the evens
  curr = evenVals; 
  cout<<"Evens: ";
  while (curr){
    cout << curr->value << " "; 
    //move to the next odd
    Node* temp = curr; 
    curr = curr->next; 
    delete temp; 
  }
  cout<< endl; 

  return 0; 
}
