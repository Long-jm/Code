#include <iostream>
using namespace std;

// DO NOT MODIFY class node
class node {
public:
    int data;
    node *next;
    node(int d=0, node *n=nullptr):data(d), next(n) {}
};

class list {
public:
   list() { head = nullptr; tail = nullptr; }
   node *head;
   node *tail;
};

list mylist; // one global list

// MODIFY THE FOLLOWING FUNCTIONS

void push_front(int x)
{
   node* newNode = new node(x,nullptr);
   if (mylist.head) {
      newNode->next = mylist.head;
      mylist.head = newNode;
   }
   else {
      mylist.head = newNode;
      mylist.tail = newNode;
   }
}

void push_back(int x)
{
  node* newNode = new node(x,nullptr);
  if (mylist.tail) {
      mylist.tail->next = newNode;
      mylist.tail = newNode;
   }
   else {
      mylist.head = newNode;
      mylist.tail = newNode;
   }
}

void remove_front()
{
   if (mylist.head->next) {
      node* temp = mylist.head;
      mylist.head = mylist.head->next;
      delete temp;
   }
   else if (mylist.head) {
      delete mylist.head;
      mylist.head = nullptr;
      mylist.tail = nullptr;
   }
   return;  
}

void remove_back()
{
   node* temp = mylist.head;
   if (!temp) {
      return;  
   }
   if (temp->next == nullptr) {
      mylist.head = nullptr;
      mylist.tail = nullptr;
      delete temp;
      return;
   }
   while (temp->next->next) {
        temp = temp->next;
   }
    delete temp->next;
    temp->next = nullptr;
    mylist.tail = temp;
}

bool empty()
{
   if (mylist.head==nullptr){
      return true;
   }
   else {return false;}  
}

// DO NOT MODIFY FUNCTIONS BELOW THIS COMMENT

void print(std::string msg)
{
   std::cout << msg << ": ";
   node *tmp = mylist.head;
   while (tmp)
     {
        std::cout << tmp->data << " " ;
        tmp = tmp->next;  
     }
   std::cout << std::endl;
}

int main()
{
   // add 0, 1, 2 to the list
   push_back(0); 
   remove_back();
   push_back(1);
   push_back(2);
   // print them out!
   print("list");
   
   return 0;
}