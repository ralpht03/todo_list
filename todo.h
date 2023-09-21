#ifndef TODO_H
#define TODO_H
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// interface for Priority class
class Priority{
  private:
        string priority; //stores the priority of the task

  public:
        void set_priority(string p);
        string get_priority();
};

// interface for Task class
class Task: public Priority{
  private:
        string to_do; //stores the task entered by user

  public:
        Task();
        void set_to_do(string td);
        string get_to_do();
       friend ostream &operator<<(ostream &os, const Task &task);
};

#endif