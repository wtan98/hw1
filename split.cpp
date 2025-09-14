/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  //when function terminates, in should be set to NULL
  //Base Case: the list has no values left  
  if (in == nullptr){
    return;
  }
      
  //create an item pointing to the current node (head)
  Node* temp = in;
  in = in->next; 

  //make sure the node is not in the list 
  temp->next = nullptr; 
    
  //when function terminates, odds/evens should point to list of odds/evens
  //even numbers divisible by 2
  if (temp->value % 2 == 0){
    //place value in evens list 
    temp->next = evens; 
    evens = temp; 
  }
  //odd if its not divisible by 2
  else if (temp->value % 2 != 0){
    temp->next = odds; 
    odds = temp; 
  }

  split(in, odds, evens);
  

}

/* If you needed a helper function, write it here */
