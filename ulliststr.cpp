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

void ULListStr::push_back(const std::string& val){
  if(head_ == nullptr || tail_->last == ARRSIZE ){ // checks to see if list is empty or if tail is full
  Item* temp = new Item();
  if(head_){
    temp->prev =  tail_;
    tail_->next = temp;
    }
    else{
    head_ = temp;
     }
    tail_ = temp;
  }
 
  tail_->val[tail_->last++] = val; // places value at the back of the ULL
  size_++;
}

void ULListStr::pop_back(){
  if(tail_ == nullptr){
    return;
  }

  tail_->last--;
  size_--;
  if(tail_->first == tail_->last){ // if the last array contains 1 string we delete this item
    Item* temp = tail_;
    tail_ = tail_->prev; // previous item becomes tail
    if(tail_){
      tail_->next = nullptr;
    }
    else{
      head_ = nullptr;
    }
    delete temp; // deletes the old tail item
    return;
  }
}

void ULListStr::push_front(const std::string& val){
  if(head_ == nullptr || head_->first == 0){ // checks to see if we need to create a new node
    Item* temp = new Item();
    temp->first = ARRSIZE-1;
    temp->last = ARRSIZE;

    if(head_){ // checks to see if the head already exists
    head_->prev = temp;
    temp->next = head_;
    }

    else{ //if it doesnt that means our head and tail will point at this new node
      tail_ = temp;
    }
    head_ = temp;
  }
  else{ // if we dont need a new node we can just increment by one down
    head_->first--;
  }

  head_->val[head_->first] = val;
  size_++;
  }


void ULListStr::pop_front(){
  if(!head_){
    return;
  }
  size_--; //decreaces size by 1;
  head_->first++; // just move the indices of the array forward 1 we don't need to do anything to the actual value
  if(head_->last == head_->first){ // if the first array contains 1 string we delete this item
    Item* temp = head_;
    head_ = head_->next; // next item becomes head
    if(head_){
      head_->prev = nullptr;
    }
    else{
      tail_ = nullptr;
    }
    delete temp; // delete the old prev item
  }
  return;

}

std::string const& ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string const& ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("Bad location");
  }

  Item* temp = head_;
  size_t index = loc;

  while(temp){ // iterates through the linked list
  size_t nsize = temp->last - temp->first;
    if(index < nsize){
      return &(temp->val[temp->first +index]);
    }
    index-= nsize;
    temp = temp->next;
  }

  return nullptr; // never should be called
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
