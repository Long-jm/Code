#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <random>
#include <string>
#include <map>
#include <algorithm>
#include <list>

using std::vector;
using std::unordered_set;
using std::map;
using namespace std;

class Edge {
public:
  Edge(int n1, int n2, int w):weight(w) {
    if (n1 < n2)
      {
	      from = n1;
	      to = n2;
      }
    else
      {
	      from  = n2;
	      to = n1;
      }
  }
  // We use from and to for convenience, but edge has no direction.
  // For convenience, require that from < to. 
  int from;
  int to;
  int weight;
  bool operator==(const Edge &other)
  {
     return other.from==from && other.to==to && other.weight == weight;  
  }
};

// DO NOT MODIFY, can be used to help sort a vector of edges
class EdgeCompare {
public:
  bool operator () (Edge &e1, Edge &e2) const {
    return e1.weight < e2.weight || (e1.weight==e2.weight && e1.from < e2.from) || (e1.weight==e2.weight && e1.from==e2.from && e1.to < e2.to);
  }
};

// Undirected Graph
class Graph {
public:
  int numNodes;
  vector<Edge> edgeV;
  Graph(int n) {
    numNodes = n;
  }  
  void addEdge(int from, int to, int weight)
  {        
    if (from >= numNodes)
      return; // silent error
    if (to >= numNodes)
      return; // silent error

    // don't add a duplicate edge
    Edge tmp(from, to, weight);
    for (auto e: edgeV) {
      if (e.from == tmp.from && e.to == tmp.to)
	return;
    }
    
    edgeV.push_back(tmp);
  }
};


using VertexSet = map<int, vector<int>* >;

// IMPLEMENT
vector<Edge> minimum_spanning_tree(Graph &graph)
{
   
   vector<Edge> edgeList = graph.edgeV;
   VertexSet vSet;
   vector<int>* vSet1;
   vector<int>* vSet2;
   VertexSet::iterator index1;
   VertexSet::iterator index2;
   
   sort (edgeList.begin(), edgeList.end(), EdgeCompare());
   int it;
   for (it=0; it<graph.numNodes; it++)
      vSet[it] = new vector<int>({it});
   vector<Edge> result;

   while ((vSet.size()>1) && (edgeList.size() > 0)) {
      Edge nextEdge = edgeList[0];
      edgeList.erase(edgeList.begin());
      auto it = vSet.begin();
      while (it != vSet.end()) {
         vector<int> *v = it->second;
         for (long unsigned int i=0; i<v->size(); i++) {
            if (v->at(i) == nextEdge.from) {
               vSet1 = it->second;
               index1 = it;
            }
            if (v->at(i) == nextEdge.to) {
               vSet2 = it->second;
               index2 = it;
            }
         }
         if ((!vSet1->empty()) && (!vSet2->empty()))
            break;
         it++;
      }
      bool same = false;
      if (vSet1 != vSet2) {
         result.push_back(nextEdge);
         vSet.erase(index1);
         vSet.erase(index2);
         for (long unsigned int j=0; j<(vSet1->size()); j++) {
            for (long unsigned int k=0; k<(vSet2->size()); k++) {
               if ((vSet1->at(j)) == (vSet2->at(k)))
                  same = true;
            }
            if (!same)
               vSet2->push_back(vSet1->at(j));
            same = false;
         }
      pair <int, vector<int>* > merged (index1->first, vSet2);
      vSet.insert(merged);
      }
   }
   return result;
}

std::ostream& operator << (std::ostream& out, const vector<Edge> &edges)
{
  for(auto i = edges.cbegin(); i!=edges.cend(); i++)
    {
      if (i!=edges.cbegin())
	out << ", ";
      out << (*i).from << "->";
      out << (*i).to << " (";
      out << (*i).weight << ")";
    }
  out << std::endl;
  return out;
}

Graph *random_graph(int nodes, int edges)
{
  Graph *g = new Graph(nodes);
  
  std::default_random_engine generator;
  std::uniform_int_distribution<int> dist(0,nodes-1);
  std::uniform_int_distribution<int> w(10,100);
  
  for(auto i = 0; i<edges; i++)
    {
      dist(generator);
      g->addEdge( dist(generator), dist(generator), w(generator) );
    }

  return g;
}

int main()
{
  Graph g(4);
  
  g.addEdge(0,1,0);
  g.addEdge(1,2,10);
  g.addEdge(2,3,0);
  g.addEdge(0,3,11);
  
  auto ev = minimum_spanning_tree(g);
  std::cout << "MST: " << ev ;
  
  return 0;
}