/*****************************************************************************
IMPORTANT :
1.Don't forget to allocate memory (adj = new list <int> [V])
2.Don't forget the iterator (list <int> :: iterator i).Its a pointer so to
  access the value  (*i) should be used.
******************************************************************************/


#include<iostream>
#include<list>
using namespace std;
int V;
list <int> *adj;
void DFS(int v,bool visited[])
{
  visited[v] = true;
  cout<<v<<" ";
  list <int>::iterator i;
  for(i=adj[v].begin();i!=adj[v].end();++i)
    if(!visited[*i])
      DFS(*i,visited);
}
int main()
{
  int v1,v2,e;
  cout<<"Enter number of vertex and edges :";
  cin>>V>>e;
  adj = new list <int> [V];   //allocate memory
  cout<<"Enter vertex 1 and vertex 2: ";
  for(int i=0;i<e;i++)
  {
    cin>>v1>>v2;
    adj[v1].push_back(v2);
  }
  bool *visited = new bool[V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  for(int i=0;i<V;i++)
    if(!visited[i])
      DFS(i,visited);
}
