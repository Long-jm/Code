#include <random>
#include <iostream>
#include <chrono>
#include <cstddef>
#include <list>
#include <functional>
#include <set>

using std::list;

class HashTable {
protected:
  list<int> *table;
  list<int> *newTable;
  size_t maxChainLength;

  // Make sure size field always shows size of table
  size_t size;
  
  size_t hash(int key, int sz) { std::hash<int> h; return h(key) % sz; }
  
  void resize(int new_size) {
    
    newTable = new list<int> [new_size];
    size_t index = 0;
    while (index < size) {
      auto it = table[index].begin();
      while(it!=table[index].end())
      {
	      if (*it) {
	        int newIndex = hash(*it,new_size);
          newTable[newIndex].push_front(*it);
        }
	      ++it;
      }
      index++;
    }
    table = newTable;
    size = new_size;
     return;
  }
  
  HashTable(const HashTable &other) = delete;
  HashTable& operator=(const HashTable &other) = delete;
  
public:
  HashTable(int htsize=1000, int maxChainL=10)
  {
    size = htsize;
    maxChainLength = maxChainL;
    table = new list<int> [size];
  }

  ~HashTable()
  {
    // this will call the destructor on each list in the table
    delete [] table;
  }

  void insert(int data) {
    int index = hash(data,size);
    list<int>::iterator ins;

    if (!find(data))
       table[index].push_front(data);
    if(table[index].size() > maxChainLength)
      resize(((this->size)*2)+3);
  }

  //override keyword asks compiler to do extra checks
  bool find(int data) 
  {
    int index = hash(data,size);

    auto it = table[index].begin();
    while(it!=table[index].end())
      {
	if ( *it == data )
	  return true;
	++it;
      }
    
    return false;
  }

  void remove(int data) 
  {
    int index = hash(data,size);
    auto it = table[index].begin();
    while(it!=table[index].end())
      {
	if (*it==data)
	  {
	    table[index].erase(it);
	    return;
	  }
	++it;
      }    
  }

  // DO NOT REMOVE OR MODIFY
  size_t getTableSize() { return size; }

  int getNumElements() {
    int num = 0;
    for(size_t i=0; i<getTableSize(); i++)
      {
	num += table[i].size();
      }
    return num;
  }

  bool checkChainLength() {
    for(size_t i=0; i<getTableSize(); i++)
      {
	if (table[i].size() > maxChainLength)
	  return false;
      }
    return true;
  }
};

using namespace std::chrono;

int main()
{
  HashTable myset(10,3);

  size_t sz = myset.getTableSize();
  
  std::cout << "Hash table is " << myset.getTableSize()
	    << " entries long." << std::endl;

  // random number generation
  std::random_device generator;
  std::uniform_int_distribution<int> dist(0,1000000);

  std::set<int> ins;
  for(int i=0; i<40; i++) {
    int val =  dist(generator);
    myset.insert(val);
    if (myset.find(val))
      ins.insert(val);
  }

  if ( myset.getTableSize() > sz ) {
    std::cout << "Table has been resized! Good job." << std::endl;
  } else {
    std::cout << "Table was not resized. Did you to remember to update size field?" << std::endl;
  }

  if ( myset.checkChainLength() )
    {
      std::cout << "All chains are <= maxChainLength." << std::endl;
    }
  else
    {
      std::cout << "At least one chain is > maxChainLength." << std::endl;
    }
    
 for(auto it = ins.begin(); it!=ins.end(); it++)
    if ( myset.find(*it) == false ) {
        std::cout << "At least one value was lost during resizing." << std::endl;
    }
  
 return 0;
}