/******************************************************************************
IMPORTANT:
1.Don't forget to allocate memory
2.use auto for iterator
3.use typedef for pair<int,int> ipair
4.use push for queue.
******************************************************************************/

#include<iostream>
#include<queue>
#include<list>
#include<vector>
#define INF 9999999
using namespace std;
typedef pair<int,int> ipair;
int V;
list <pair<int,int>> *adj;
int main()
{
  int e,v1,v2,w;
  cout<<"Enter number of vertex and edges: ";
  cin>>V>>e;
  adj = new list<ipair> [V];
  cout<<"Enter vertex 1 and vertex 2 and weight : ";
  for(int i=0;i<e;i++)
  {
    cin>>v1>>v2>>w;
    adj[v1].push_back(make_pair(v2,w));
    adj[v2].push_back(make_pair(v1,w));
  }
  priority_queue <ipair,vector<ipair>,greater<ipair>> pq;
  vector <int> key(V,INF);  //store weight
  vector <bool> mst(V,false);
  vector <int> parent(V,-1);  //store mst
  int src = 0;
  pq.push(make_pair(0,src));
  key[src] = 0;
  while(!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
    mst[u] = true;
    for(auto i : adj[u])
    {
      int v = i.first;
      int weight = i.second;
      if(mst[v] == false && key[v] > weight)
      {
        key[v] = weight;
        pq.push(make_pair(key[v],v));
        parent[v] = u;
      }
    }
  }
  for(int i = 1;i < V;i++)
  {
    cout<<parent[i]<<" : "<<i<<endl;
  }
}
