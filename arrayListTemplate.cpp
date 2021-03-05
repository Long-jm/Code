#include <iostream>
#include <vector>

using namespace std;

template <typename Item>
class ArrayList {
   
public:
  vector<Item> aList;
  ArrayList(size_t asize=10) {}

  /*~ArrayList() 
  { 
    delete aList;
  }

  ArrayList(const ArrayList &other)
  {
    vector<Item> cList(other.capacity);
    cList = aList;  
  }

  ArrayList& operator= (const ArrayList &other)
  {
    vector<Item> cList(other.capacity);
    cList = aList;
    return *this;     
  }*/

  void insertAt(Item a, size_t index=0) 
  {
    //typename vector<Item>::iterator vector<Item>::insert(vector<Item>::iterator it, a)
    typename vector<Item>::iterator it = aList.begin() + index;
    aList.insert(it, a);    
    return; 
  }
  Item& at(size_t index)
  {
    return aList.at(index);
  }
  void remove(size_t index)
  {
    typename vector<Item>::iterator it = aList.begin() + (int)index - 1;
    aList.erase(it);
    return;
  }
  bool empty() {
    return aList.empty();
  }
  size_t find(Item item) 
  {
    size_t index = 0;
    while (index < aList.size() && item != aList.at(index)) {
      index++;
    }
    return index; 
  }
  size_t size() 
  {
    return aList.size(); 
  }
};

// DO NOT MODIFY BELOW HERE
template <typename T>
ostream& operator<< (ostream& out, ArrayList<T> &array)
{
   out << "[";
   for (size_t i=0; i<array.size(); i++)
   {
      out << array.at(i) << ",";  
   }
   out << "]";
   return out;
}

int main()
{
   ArrayList<int> l;
   
   for (int i=0; i<5; i++) {
     l.insertAt(i,l.size());
   }  
   
   size_t index = l.find(5);
     
   cout << l <<" "<< index << endl;
   
   return 0;
}