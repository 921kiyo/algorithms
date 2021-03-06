// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

#include <iostream>
#include <list>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

// This class represents a directed graph using adjacency list representation
class Graph{
  int V; // No. of vertices

  // In a weighted graph, we need to store vertex and weight pair for every edge
  list< pair<int, int>> *adj;

public:
  // Allocate memory for adjacency list
  Graph(int V){
    this->V=V;
    adj = new list<iPair>[V];
  }

  void addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  void shortestPath(int src){
    // Create a priority queue to store vertices that are being processed.
    priority_queue< iPair, vector<iPair>, greater<iPair>> pq;

    // Creates a vector for distances and initialise all distances as inifinite
    vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialise its distance as 0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()){
      // The first vertex in pair is the minimum distance Vertex
      // extract it from priority queue
      // Vertex label is stored in second of pair
      int u = pq.top().second;
      pq.pop();

      // i is used to get all adjacent vertices of a vertex
      list<pair<int, int>>::iterator i;

      for(i = adj[u].begin(); i != adj[u].end(); i++){
        // Get vertex label and weight of current adjacent of u
        int v = (*i).first;
        int weight = (*i).second;

        // If there is a shortest parth to v through u
        if(dist[v] > dist[u] + weight){
          // Update distance of v
          dist[v] = dist[u] + weight;
          pq.push(make_pair(dist[v], v));
        }
      }
    }

    printf("Vertex Distance from Source\n");
    for(int i = 0; i < V; i++){
      printf("%d \t\t %d\n", i, dist[i]);
    }

  }
};

// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
