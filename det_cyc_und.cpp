// A C++ Program to detect cycle in an undirected graph
#include<iostream>
#include <list>
#include <limits.h>
using namespace std;
int V; // No. of vertices
list <int> *adj; // Pointer to an array containing adjacency lists
bool isCyclicUtil(int v, bool visited[], int parent)
{
	visited[v] = true;
	for (auto i : adj[v])
	{
		if (!visited[i])
		{
		if (isCyclicUtil(i, visited, v))
			return true;
		}
		else if (i != parent)
		return true;
	}
	return false;
}

bool isCyclic()
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int u = 0; u < V; u++)
		if (!visited[u]) // Don't recur for u if it is already visited
		if (isCyclicUtil(u, visited, -1))
			return true;
	return false;
}
int main()
{
  int v1,v2,e;
  cout<<"Enter number of edges and vetex : ";
  cin>>e>>V;
  adj = new list<int>[V];
  cout<<"Enter vertex 1 and vertex 2 : ";
  for(int i=0;i<e;i++)
  {
    cin>>v1>>v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }
	if(isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}
