// A C++ Program to detect cycle in a graph
#include<iostream>
#include <list>
#include <climits>
using namespace std;
int V; // No. of vertices
list <int> *adj; // Pointer to an array containing adjacency lists
bool isCyclicUtil(int v, bool visited[], bool *recStack)
{
	if(visited[v] == false)
	{
		visited[v] = true;      // Mark the current node as visited and part of recursion stack
		recStack[v] = true;
		for(auto i : adj[v])    // Recur for all the vertices adjacent to this vertex
		{
			if ( !visited[i] && isCyclicUtil(i, visited, recStack) )
				return true;
			else if (recStack[i])
				return true;
		}
	}
	recStack[v] = false; // remove the vertex from recursion stack
	return false;
}
bool isCyclic()
{
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}
	for(int i = 0; i < V; i++)
		if (isCyclicUtil(i, visited, recStack))
			return true;
	return false;
}

int main()
{
  int v1,v2,w,e;
  cout<<"Enter number of edges and vetex : ";
  cin>>e>>V;
  adj = new list<int>[V];
  cout<<"Enter vertex 1 and vertex 2 : ";
  for(int i=0;i<e;i++)
  {
    cin>>v1>>v2;
    adj[v1].push_back(v2);
  }
	if(isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}
