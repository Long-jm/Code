#include <iostream>
#include <list>
#include <set>

#define Q   (4) 

using namespace std;

class Squared 
{
public: 
   int operator() (int x) { return x*x; }
};

class HashTable 
{
protected:
   list<int> *table;
   list<int> *newTable;
   
   size_t size;
   #if Q == 3
   size_t hash(int key, int sz) { std::hash<int> h; return h(key) % sz; }
   #endif
   #if Q == 4
   size_t hash(int key, int sz) { std::hash<int> h; return h(key ^ 677) % sz;
   #endif
   
   HashTable(const HashTable &other) = delete;
   HashTable& operator=(const HashTable &other) = delete;
   
   public:
   HashTable(int htsize=11)
   {
      size = htsize;
      table = new list<int> [size];
   }

   ~HashTable()
   {
      delete [] table;
   }

   void insert(int data) 
   {
      int index = hash(data,size);
      while (!table[index].empty())
      {
         index++;
      }
      table[index].push_front(data);
   }
};

int main() 
{
   
   #if Q == 1
   int val = 4;
   Squared sObj;
   cout << "val = " << val << " val^2 = " << sObj(val) << endl;
   return 0; 
   #endif

   #if Q == 2
   int searchVal = 5;
   set<int> Set;
   list<int> List;
   bool lFound = false, sFound = false;

   for (int i=0; i<=searchVal; i++)
   {
      Set.insert(i);                   // fill set
      List.push_back(i);               // fill list
   }
   auto sIt =Set.find(searchVal);      
   if (sIt != Set.end())               // search set
         sFound = true;

   auto lIt = find(List.begin(), List.end(), searchVal);
   if (lIt != List.end())              // search list
      lFound = true;    
   
   cout << "Set = { ";                 // print set
   for (int n : Set) 
   {
      cout << n << ", ";
   }
   cout << "}; Found searchVal = (bool) " << sFound << endl;

   cout << "List = { ";                // print list
   for (int n : List) 
   {
      cout << n << ", ";
   }
   cout << "}; Found searchVal = (bool) " << lFound << endl;
   #endif
   
   #if Q == 3

   HashTable HT;
   HT.insert(23);
   HT.insert(52);
   HT.insert(90);
   HT.insert(56);
   HT.insert(134);
   HT.insert(110);
   HT.insert(8);
   
   #endif
}
