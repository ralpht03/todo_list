#include "list.h"
#include "todo.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;

/****************************************
This is a program to create a to-do-list.
It allows a user to perform various operations on the list.
It presents a menu of options that the user can choose from.
The user inputs a number to choose an option and the program
will continue to present the menu of option until the user
chooses to exit.
*************************************************************/
int main(){

    cout<<endl<<"**************** To Do List ****************"<<endl<<endl;

    // creating a Clist object
    CList<Task> list;

    int option;

    // do while loop that displays the menu for the use to chose from
    do{
        cout<<"What operation do you want to perform. Select a number to choose an option. Select 0 to exit the page."<<endl;
        cout<<"1. Add a task to the list."<<endl;
        cout<<"2. Remove task from the list."<<endl;
        cout<<"3. Check if list empty."<<endl;
        cout<<"4. Check task at front"<<endl;
        cout<<"5. Check task at end."<<endl;
        cout<<"6. Display the list."<<endl;

        while (!(cin>>option)) {       // checking if user input is a number
                cout << "Invalid input. Enter an integer number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } 
        cout<<endl;

        // switch cases to perform oeration chosen by the user
        switch(option){

            case 0: 
                break;

            case 1:
                list.add();
                cout<<"Task added."<<endl<<endl;
                break;

            case 2:
                if (list.empty()) {
                    cout<<"The list is empty."<<endl<<endl;
                }else{
                    list.remove();
                    cout<<"First Task removed."<<endl<<endl;
                }
                break;
        
            case 3:
                if (list.empty()) {
                    cout<<"The list is empty."<<endl<<endl;
                }else{
                    cout<<"This list is not empty."<<endl<<endl;
                }
                break;

            case 4:
                if (list.empty()) {
                    cout<<"The list is empty."<<endl<<endl;
                }else{
                    list.front();
                }
                break;

            case 5:
                if (list.empty()) {
                    cout<<"The list is empty."<<endl<<endl;
                }else{
                    list.back();
                }
                break;

          case 6:
                list.display();
                break;

            default: 
                cout<<"Invalid option."<<endl;
        }
    }while(option != 0);

    cout<<"Bye see you next time!"<<endl;

    return 0;
}

// setting cursor to NULL
template <typename T>
CList<T>::CList(){
  cursor = NULL;
}

// destructor for list
template <typename T>
CList<T>::~CList(){
  while(!empty()){
    remove();
  }
}

// function to check if the list is empty
template <typename T>
bool CList<T>::empty() const{
  return (cursor == NULL);
}

// this function prints out the first element on the list
template <typename T>
void CList<T>::front(){
  if(cursor->next->data.get_priority() == "High"){
    cout<<cursor->next->data.get_to_do()<<" **IMPORTANT TASK**"<<endl<<endl;
  }
  else{
    cout<<cursor->next->data.get_to_do()<<endl<<endl;
  }
}

// this function prints out the last element on the list
template <typename T>
void CList<T>::back(){
  if(cursor->data.get_priority() == "High"){
    cout<<cursor->data.get_to_do()<<" **IMPORTANT TASK**"<<endl<<endl;
  }
  else{
    cout<<cursor->data.get_to_do()<<endl<<endl;
  }
}

// this function advances the cursor
template <typename T>
void CList<T>::advance(){
  cursor = cursor->next;
}

// function to add an element to the list
template <typename T>
void CList<T>:: add(){
  Node<T> *new_elem = new Node<T>;
  if(cursor == NULL){
    new_elem->next = new_elem;
    cursor = new_elem;
  }
  else{
    new_elem->next = cursor->next;
    cursor->next = new_elem;
  }
  advance();
}

// function to remove element at the top of the list
template <typename T>
void CList<T>:: remove(){
  Node<T> *old = cursor->next;
  if(old == cursor){
    cursor = NULL;
  }
  else{
    cursor->next = old->next;
  }
  delete old;
}

// function to display all elements to the screen
template <typename T>
void CList<T>::display(){
  if (empty()) {
    cout<<"The list is empty."<<endl<<endl;
    return;
  }
  Node<T> *p;
  p = cursor->next;
  while(p != NULL && p != cursor){
    if(p->data.get_priority() == "High"){
      cout<<p->data.get_to_do()<<" **IMPORTANT TASK**"<<endl;
    }
    else{
    cout<<p->data.get_to_do()<<endl;
    }
    p = p->next;
  }
  if(cursor->data.get_priority() == "High"){
    cout<<cursor->data.get_to_do()<<" **IMPORTANT TASK**"<<endl;
  }
  else{
    cout<<cursor->data.get_to_do()<<endl<<endl;
  }
}

// setter function for Priority class
void Priority::set_priority(string p){
  priority = p;
}

// getter function for Priority class
string Priority::get_priority(){
  return priority;
}

// constructor for Task class prompts the user about information for a specific class
Task::Task(){
  string td;
  cout<<"Enter task: ";
  cin.ignore();
  getline(cin, td);
  to_do = td;
  string choice;
  int p;
  cout<<"Would you like to add a priority to this task? (y/n): ";
  cin>>choice;
  
  if(choice == "y" || choice == "yes"){
    cout<<"Type 1 for high priority or 2 for low priority: ";
    
    while (!(cin>>p)) {       // checking if user input is a number
      cout << "Invalid input. Enter an integer number: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
    
    switch(p){
      case 1:
        this->set_priority("High");
        break;

      case 2:
        this->set_priority("Low");
        break;
    }
  }
}

// setter function for Task class
void Task::set_to_do(string td){
  to_do = td;
}

// getter function for Task class
string Task::get_to_do(){
  return to_do;
}

// overloading method that helps display data from objects of type Task to the screen
ostream &operator<<(ostream &os, const Task &task){
  os<<task.to_do;
  return os;
}
