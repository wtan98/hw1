#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  //case 1: empty array
  if(empty()){
    head_ = new Item(); 
    tail_ = head_;

    //assign val to beginning of arr and make the next index avail 
    tail_->val[0] = val;
    tail_->first = 0; 
    tail_->last = 1; 
  }
  //case 2: there is space at the end of the arr
  else if(tail_->last < ARRSIZE){
    size_t nextAvalInd = tail_->last; 
    tail_->val[nextAvalInd] = val; 

    //update last so it is now at the end
    tail_->last += 1; 
  }
  //case 3: there is no more space in the arr; make new node 
  else{
    Item* newArr = new Item();

    //connect the new array with old array 
    newArr->prev = tail_; 
    tail_->next = newArr; 

    //now assign the val to the new arr 
    newArr->val[0] = val;
    newArr->first = 0;
    newArr->last = 1;
    
    tail_ = newArr; 
  }
  
  size_ +=1; 
}

void ULListStr::push_front(const std::string& val)
{
  //case 1: empty array
  if(empty()){
    head_ = new Item(); 
    tail_ = head_;

    //assign first val 
    tail_->val[0] = val;
    tail_->first = 0; 
    tail_->last = 1; 
  }
  //case 2: theres space in beginning of arr; move first backwards
  else if(head_->first != 0){
    head_->first -= 1; 
    size_t newFirst = head_->first; 
    head_->val[newFirst] = val; 
  }
  else{
    //case 3: theres no space
    Item* newArr = new Item();
    newArr->val[0] = val; 
    newArr->first = 0;
    newArr->last = 1;

    //connect new arr to the beg of old arr 
    newArr->next = head_; 
    head_->prev = newArr;
    head_ = newArr; 
  }

  size_+=1; 
} 

void ULListStr::pop_back()
{
  //check if empty
  if(empty()){
    return; 
  }

  //remove the item 
  tail_->last -= 1; 
  size_-=1; 

  //check if last node is empty
  int n = tail_->last - tail_->first; 
  if(n == 0){
    Item* delVal = tail_;  
    //tail_->next = nullptr;

    //check if there is only 1 node
    if(tail_ == head_){
      tail_= nullptr; 
      head_= nullptr;
    }
    else{
      tail_ = tail_->prev;
      tail_->next = nullptr; 
    }
    
    delete delVal; 
  }
}

//same thing but removing the front now
void ULListStr::pop_front()
{
  //check if empty
  if(empty()){
    return; 
  }

  //update index 
  head_->first +=1; 
  size_-=1; 

  int n = head_->last - head_->first;
  if(n==0){
    Item* delVal = head_; 
    
    //1 node left
    if(head_ == tail_){
      tail_= nullptr;
      head_= nullptr; 
    }
    else{
      head_ = head_->next; 
      head_->prev = nullptr;
    }

    delete delVal; 
  }
}

std::string const & ULListStr::back() const
{
  Item* endNode = tail_; 
  size_t endIndex = endNode->last-1; 
  return endNode->val[endIndex];
}

std::string const & ULListStr::front() const
{
  //dont lose head
  Item* begNode = head_; 
  size_t firstIndex = begNode -> first; 
  return begNode->val[firstIndex];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{

  //check if loc is bigger than arr 
  if (loc>=size_){
    return nullptr; 
  }

  Item* curr = head_; 
  size_t n = 0; 

  while(curr != nullptr){
    //go through array in curr node 
    for (size_t i = curr->first; i < curr->last; i++){
      if (n==loc){
        return &curr->val[i];
      }
      n++; 
    }
    //move to next node
    curr= curr->next; 
  }

  return nullptr; 
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}


std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
