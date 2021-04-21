#include <list>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main () {
   list<double> doubleList;
   vector<char> byteVector;
   set<int> BTreeSet;
   unordered_set<string> HashSet;
   pair<int,int> xyPair;
   //unordered_map< pair<int,int>,string > xyString;
   list< pair<int,int> > xyList;
   unordered_map<string,long int> NameNumHashMap;
   unordered_map<long int,string> NumNameHashMap;
   vector < vector<string> > stringVector2D;
   return 0;
}
