/******************************************************************************
Name : Maurya Sujeet
Roll no. : 17BCS016
Code : Topological Sorting
*******************************************************************************/
#include<iostream>
#include<stack>
#include<list>
using namespace std;
int V;
list <int> *a;
void mark_visited(int v,bool visited[],stack <int> &Stack)
{
  visited[v]=true;
  list <int> :: iterator i;
  for(i = a[v].begin();i!=a[v].end();++i)
    if(!visited[*i])
      mark_visited(*i,visited,Stack);
  Stack.push(v);
}
void topo_sort()
{
  stack <int> Stack;
  bool *visited = new bool[V];
  for(int i=0;i<V;i++)
    visited[i] = false;
  for(int i=0;i<V;i++)
    if(visited[i] == false)
      mark_visited(i,visited,Stack);
  while(!Stack.empty())
    {
      cout<<Stack.top()<<" ";
      Stack.pop();
    }
}
int main()
{
  int e;
  cout<<"Enter number of vertex and edges: ";
  cin>>V>>e;
  a = new list <int> [V];
  int n,c1,c2;
  for(int i=0;i<e;i++)
  {
    cout<<"Enter vertex number : in direcion from one vertex to another : "<<endl;
    cin>>c1>>c2;
    a[c1].push_back(c2);
  }
  cout<<"Topological sort: ";
  topo_sort();
}
