#include <cstddef>
#include <stdexcept>
#include <vector>
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
void ULListStr::push_back(const std::string& val){
// list is empty
  if(head_==NULL){
    head_ = new Item;
    head_->last = 1;
    head_->val[0]=val;
    tail_=head_;
    size_++;
  }
// list is not empty
// tail Item full
  else if(tail_->last==10){
    Item* newitem = new Item;
    newitem->prev=tail_;
    newitem->next=NULL;
    tail_->next=newitem;
    tail_=newitem;
    tail_->val[0]=val;
    (tail_->last)++;
    size_++;
  }
//tail item not full
  else{
    tail_->val[tail_->last]=val;
    (tail_->last)++;
    size_++;
  }
}

void ULListStr::pop_back(){
  if(head_==NULL){return;}
  else{
    if(tail_->last<=1){
      Item* temp=tail_;
      tail_=tail_->prev;
      if(tail_ != NULL){
        tail_->next=NULL;
      }
      else{
        head_=NULL;
      }
      delete temp;
    }
    else{
      (tail_->last)--;
    }
    size_--;
  }
}

void ULListStr::push_front(const std::string& val){
  if(head_==NULL){
    head_ = new Item;
    head_->last = 10;
    head_->first=9;
    head_->val[9]=val;
    tail_=head_;
    size_++;
  }
  else{
    if(head_->first==0){
      Item* newitem = new Item;
      newitem->next=head_;
      newitem->prev=NULL;
      head_->prev=newitem;
      head_=newitem;
      head_->val[9]=val;
      head_->first=9;
      head_->last=10;
    }
    else{
      head_->first--;
      head_->val[head_->first]=val;
    }
    size_++;
  }
}

void ULListStr::pop_front(){
  if(head_==NULL){return;}
  else{
    if(head_->first==9){
      Item* temp=head_;
      head_=head_->next;
      if(head_!=NULL){
        head_->prev=NULL;
      }
      else{
        tail_=NULL;
      }
      delete temp;      
    }
    else{
      head_->first++;
    }
  }
  size_--;
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc >= size_ || head_ == NULL) 
    {return NULL;}

  Item* curr = head_;
  size_t index = loc;

  while (curr != NULL) {
    size_t numElements = curr->last - curr->first;

    if (index < numElements) {
      return &(curr->val[curr->first + index]);
    } 
    else 
    {
      index -= numElements;
      curr = curr->next;
    }
  }
  return NULL;
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