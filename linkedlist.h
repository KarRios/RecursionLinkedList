//begin linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node {
    int data;
    node * next;
};

class linkedlist {
private:
    node * head;
    int count(); // RECURSIVE
    int count(node * ptr);
    int sum(); // RECURSIVE
    int sum(node * ptr);

public:
    linkedlist();
    ~linkedlist(); // RECURSIVE
    void deleteNodes(node * ptr);
    void addToFront(int n);
    double average(); // uses sum and count functions
    void writeInorder(string & file);
    void writeReversed(string & file);
    void write(ofstream & file, node * ptr);
    void reverse(node * ptr);  
    void print();
    void print(node * ptr);
};
#endif // end linkedlist.h
