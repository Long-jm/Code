#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
#include <vector>
#include <random>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

#define INT_MAX      (2147483647)

using namespace std;

class Edge {
public:
  Edge(int src, int dest, int w):from(src),to(dest),weight(w){}
  int from;
  int to;
  int weight;
  bool operator==(const Edge &other)
  {
     return other.from==from && other.to==to && other.weight == weight;  
  }
};

// Directed Graph: nodes must be labeled from 0 to n-1
// DO NOT CHANGE DirectedGraph
class DirectedGraph {
public:
  int numNodes;
  map<int, vector<Edge> > adjList; 

  DirectedGraph(int n) {
    numNodes = n;
  }  
  void addEdge(int from, int to, int weight)
  {
     if (from >= numNodes || to >= numNodes || from < 0 || to < 0) {
        cout << "error: node number too larg or too small." << endl;
        return;
     }
     adjList[from].push_back(Edge(from, to, weight));
  }
};

// The following struct and using declaration may be helpful, but you are not
// required to use it. You may change them as you see fit.

struct VertexInfo {
  int distance;
  int predV;
  int weight;
  int from;
  VertexInfo():distance(INT_MAX), predV(-1), weight(INT_MAX), from(0) {}
};
/*using ShortestPathInfo = unordered_map<int, VertexInfo>;  ????????????*/

// IMPLEMENT THIS FUNCTION. 
// Do not change arguments, types, order of arguments, or return value type.
// Arguments:
//    graph: graph to analyze
//    from: node to start at
//    to: node to end on
//    path: found shortest path from->to
// Return: true if path found, false otherwise.
// Restrictions: (1) from and to must be different nodes, 
//               (2) a graph with no nodes always returns false
//               (3) all weights are > 0.
//
bool shortest_path(DirectedGraph &graph, int from, int to, list<int> &path)
{
   unordered_map<int, VertexInfo> dots;
   priority_queue <int, vector<int>, greater<int> > minUnvisited;

   if (graph.numNodes)
      path.push_back(from);
   else return false;

   for(int i=0; i<graph.numNodes; i++) {
     struct VertexInfo v;
     pair<int,VertexInfo> duo (i,v); 
     dots.insert(duo);
     minUnvisited.push(i);
   }
   dots[from].distance = 0;
   while (!minUnvisited.empty()) {
      int currentV = minUnvisited.top();
      minUnvisited.pop();
      for (auto it : graph.adjList[currentV]) {
         int edgeWeight = it.weight;
         int altPathDist = dots[currentV].distance + edgeWeight;
         if (altPathDist < dots[it.to].distance) {
            dots[it.to].distance = altPathDist;
            dots[it.to].predV = currentV;
         }
      }
   }
   int temp = to;
   while (dots[temp].predV) {
      path.push_front(dots[temp].predV);
      temp = dots[temp].predV;
   }
   if (!path.empty())
      return true;
   else return false;
}

// DO NOT MODIFY THESE FUNCTIONS BELOW THIS POINT:
std::ostream& operator << (std::ostream& out, vector<Edge> &edges)
{
  for(auto i = edges.cbegin(); i!=edges.cend(); i++)
    {
      if (i!=edges.cbegin())
	out << ", ";
      out << (*i).from << "->";
      out << (*i).to << " (";
      out << (*i).weight << ")";
    }
  return out;
}

std::ostream & operator << (std::ostream& out, DirectedGraph &g)
{
   for(int i=0; i<g.numNodes; i++)
     out << "node[" << i << "] = {" << g.adjList[i] << "}" << endl;    
     
   return out;
}

DirectedGraph *random_graph(int nodes, int edges)
{
  DirectedGraph *g = new DirectedGraph(nodes);
  
  std::default_random_engine generator;
  std::uniform_int_distribution<int> dist(0,nodes-1);
  std::uniform_int_distribution<int> w(1,10);
  
  for(auto i=0; i<nodes; i++)
  {
     g->addEdge( i, i+1, 50);  
  }
  
  for(auto i = 0; i<edges; i++)
    {
      dist(generator);
      g->addEdge( dist(generator), dist(generator), w(generator) );
    }

  return g;
}

int main()
{
  DirectedGraph g(4);
  
  g.addEdge(0,1,0);
  g.addEdge(1,2,10);
  g.addEdge(1,3,5);
  g.addEdge(2,3,1);
  g.addEdge(3,1,1);
  
  std::list<int> path;
  bool found = shortest_path(g,0,3, path);
  if (found) {
     std::cout << "Path: " ;
     for (auto n : path)
       std::cout << n << " ";
     std::cout << endl;
  }  
  return 0;
}