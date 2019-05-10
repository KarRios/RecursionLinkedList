#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "linkedlist.cpp"

using namespace std;

void readFile(linkedlist & list, string & file){
  int data;
  vector<int> vec;
  ifstream link;
  link.open(file);
  while(link >> data){
    vec.push_back(data);
  }
  sort(vec.begin(),vec.end());
  for(int i = vec.size()-1; i >= 0; i--){
    list.addToFront(vec.at(i));
  }
  cout << vec.size() << "\n";
  vec.clear();
}


int main() {
  string file = "list.txt";
  linkedlist list;

  readFile(list,file);

  cout << "The average is: " << list.average() << endl;

  list.print();
  list.writeInorder(file);
  list.writeReversed(file);


  return 0;
}
