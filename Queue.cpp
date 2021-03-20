#include <iostream>
#include <climits>
#include <fstream>
#include <string>
#include <list>

using namespace std;

// IMPLEMENT THE Queue CLASS
class Queue {
 private:
  unsigned int max;
 public:
  //Queue may have no more strings than maxsize
  Queue (int maxsize=INT_MAX){ max = maxsize; }

  list<string> sList;

  // Return true if it can be inserted, return
  // false if there are already maxsize strings
  // and it can't handle anymore
  bool push(string);

  // Same as defined in the book/lecture
  void pop();
  string & peek();

  // Return number of strings currently in the Queue
  size_t getSize();
};


bool Queue::push(string i)
{
  if (sList.size() < this->max) {
    sList.push_back(i);
    if (sList.back() == i) {
      return true;
    } else {return false;}
  }
  else {return false;}
}

void Queue::pop()
{
  return sList.pop_front();
}

string& Queue::peek()
{
  return sList.front();
}

size_t Queue::getSize()
{
  return sList.size();
}

int main() {

  Queue s;

  s.push("apples");
  s.push("bread");
  s.push("snack");

  string &i = s.peek();
  std::cout << i << std::endl;
  
  return 0;
}
