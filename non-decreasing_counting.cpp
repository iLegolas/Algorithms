#include<iostream>
using namespace std;
#define range 1000000
int count(unsigned int n[],unsigned int k,unsigned int t)
{
  int i;
  unsigned int c[range],b[t];
  for(i=0;i<=k;i++)
    c[i]=0;
  for(i=1;i<=t;i++)
    c[n[i]]++;
  for(i=1;i<=k;i++)
    c[i]=c[i]+c[i-1];
  for(i=t;i>=1;i--)
  {
    b[c[n[i]]]=n[i];
    c[n[i]]--;
  }
  for(i=1;i<=t;i++)
    cout<<b[i]<<endl;
}
int main()
{
  unsigned int t,n[range],k=0;
  int i;
  cin>>t;
  for(i=1;i<=t;i++)
  {
    cin>>n[i];
    if(n[i]>k)
      k=n[i];
  }
  count(n,k,t);
}
