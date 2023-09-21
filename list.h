#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "todo.h"

using namespace std;

// interface for Node class
template <typename T>
class Node{
  public:
    T data;
    Node<T> *next;
};

// interface for circularly linked list class with corresponding methods
template <typename T>
class CList{
  private:
    Node<T> *cursor;

  public:
    CList();
    ~CList();
    bool empty() const;
    void front();
    void back();
    void advance();
    void add();
    void remove();
    void display();
};

#endif