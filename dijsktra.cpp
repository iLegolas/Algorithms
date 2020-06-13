// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
int V;
list <pair<int, int> > *adj;
// Prints shortest paths from src to all other vertices
void shortestPath(int src)
{
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
	vector<int> dist(V, INF);
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		list< pair<int, int> >::iterator i;
		for (auto i : adj[u])
		{
			int v = i.first;
			int weight = i.second;
			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program to test methods of graph class
int main()
{
  int e,v1,v2,w;
  cout<<"Enter number of vertex and edges: ";
  cin>>V>>e;
  adj = new list<iPair> [V];
  cout<<"Enter vertex 1 and vertex 2 and weight : ";
  for(int i=0;i<e;i++)
  {
    cin>>v1>>v2>>w;
    adj[v1].push_back(make_pair(v2,w));
    adj[v2].push_back(make_pair(v1,w));
  }
  shortestPath(0);
	return 0;
}
