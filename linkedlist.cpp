#include "linkedlist.h"

linkedlist::linkedlist() {
  head = nullptr;
}

linkedlist::~linkedlist() {
    // RECURSIVE
  deleteNodes(head);
}

void linkedlist::deleteNodes(node * ptr){
  node * temp1;
  node * temp2;

  temp1 = ptr;

  while(temp1 != nullptr){
    temp2 = temp1->next;
    free(temp1);
    temp1 = temp2;
  }
}

int linkedlist::count(){
  return count(head);
}

int linkedlist::count(node * ptr) {
  if (ptr == nullptr){
    return 0;
  }
  return 1 + count(ptr->next);
}

void linkedlist::addToFront(int n) {
  node * temp = new node;
  temp->data = n;
  temp->next = head;
  head = temp;
  
}

double linkedlist::average() {
  return double(sum())/double(count());
}

int linkedlist::sum(){
  return sum(head);
}

int linkedlist::sum(node * ptr) {
  if(ptr == nullptr){
    return 0;
  }
  return ptr->data + sum(ptr->next);
}

void linkedlist::writeInorder(string & file) {
  ofstream data;
  data.open(file, ofstream::app);
  data << '\n';
  write(data,head);
  data.close();
}

void linkedlist::writeReversed(string & file) {
    // RECURSIVE
  reverse(head);

  ofstream data;
  data.open(file, ofstream::app);
  data << '\n';
  write(data,head);
  data.close();
}

void linkedlist::write(ofstream & file,node * ptr){
  if(ptr == nullptr)
    return;
  while(ptr != nullptr){
    file << ptr->data << " ";
    ptr = ptr->next;
  }
}
  

void linkedlist::reverse(node * ptr){
  if(ptr->next == nullptr){
      head = ptr;
      return;
    }

    reverse(ptr->next);
    node * temp = new node;
    temp = ptr->next;
    temp->next = ptr;
    ptr->next = nullptr;
}

void linkedlist::print(){
  print(head);
}

void linkedlist::print(node * ptr){
  if(ptr == nullptr)
    return;
  std::cout << ptr->data << " ";
  print(ptr->next);
  std::cout << "\n";
}
