/*****************************************************************************
IMPORTANT :
1.Don't forget to allocate memory (adj = new list <int> [V])
2.Don't forget the iterator . Use auto i = adj[s]

******************************************************************************/

#include<iostream>
#include<list>
using namespace std;
int V;
list <int> *adj;
int main()
{
  int v1,v2,e,start;
  cout<<"Enter number of vertex and edges : ";
  cin>>V>>e;
  adj = new list <int> [V];
  cout<<"\nEnter vertex 1 and vertex 2 : ";
  for(int i=0;i<e;i++)
  {
    cin>>v1>>v2;
    adj[v1].push_back(v2);
  }
  cout<<"\nSelect the starting vertex : ";
  cin>>start;
  bool *visited = new bool [V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  list <int> queue;
  visited[start] = true;
  queue.push_back(start);
  cout<<"Following is the breadth for search travesal (starting from index "<<start<<")"<<endl;
  while(!queue.empty())
  {
    start = queue.front();
    cout<<start<<" ";
    queue.pop_front();
  //  list <int>:: iterator i;
    for(auto i : adj[start])
      if(!visited[i])
        {
          visited[i]=true;
          queue.push_back(i);
        }
  }
  cout<<endl;
}
