#include <iostream>
using namespace std;

// DO NOT MODIFY class node
class node {
public:
    int data;
    node *prev;
    node *next;
    node(int d=0, node *p=nullptr, node *n=nullptr):data(d), prev(p), next(n) {}
};

node *head = nullptr;
node *tail = nullptr;

// MODIFY THE FOLLOWING FUNCTIONS

//1. insert(int x,node* n=nullptr):  add x after node n; add to beginning if n==nullptr

void insert(int x, node *n=nullptr)
{
   node* newNode = new node(x,n);
   if(n) {
      if (n==tail) {
        newNode->next = n->next;
        newNode->prev = n;
        n->next = newNode;
        tail = newNode;
      }
      else {
        newNode->next = n->next;
        newNode->prev = n;
        n->next = newNode;
      }
   }
   else {
      if (head) {
         head->prev = newNode;
         newNode->next = head;
         head = newNode;
      }
      else {
         head = newNode;
         tail = newNode;
      }
   }
}

//2.  remove(node*): remove node pointed to by n

void remove(node *n) 
{
   if (n==head) {
       n->next->prev = n->prev;
       head = head->next;
       delete n;
   } else if (n==tail) {
        tail = tail->prev;
        tail->next = nullptr;
        delete n;
   } else {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
   }
}

//3.  find(int x): return the first node with the value x, nullptr if not found

node* find(int x)
{
   node* i;
   i=head;
   while(i != tail) {
      if (i->data == x) {
         return i;  
      }
      else i = i->next;
   }
   return i;  
   return nullptr;
   
}

//4. reverse(): reverse the contents of the list

void reverse()
{
   node* swap=head;
   node* temp;
   
   swap->prev = swap->next;
   swap->next = nullptr;
   tail = swap;
   swap = swap->prev;
   
   while (swap->next) {
      temp = swap->prev;
      swap->prev = swap->next;
      swap->next = temp;
      swap = swap->prev;
   }
   swap->next = swap->prev;
   swap->prev = nullptr;
   head = swap;
}

// DO NOT MODIFY FUNCTIONS BELOW THIS COMMENT

bool empty()
{
   return head==nullptr;  
}

void print(std::string msg)
{
   std::cout << msg << ": ";
   node *tmp = head;
   while (tmp)
     {
        std::cout << tmp->data << " " ;
        tmp = tmp->next;  
     }
   std::cout << std::endl;
}

int main()
{
   for(int i=0; i<10; i++) insert(i,tail); 
   reverse();
   print("list");
   return 0;
}
