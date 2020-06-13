#include<iostream>
#include<climits>
using namespace std;
void parenthesis(int a[],int n)
{
  int m[n+1][n+1]={0},s[n+1][n+1]={0},i,j,d,q;
  for(d=1;d<n-1;d++)
  {
    for(i=1;i<n-d;i++)
    {
      j=i+d;
      m[i][j] = INT_MAX;
      for(int k=i;k<=j-1;k++)
      {
        q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
        if(q<m[i][j])
          {
            m[i][j]=q;
            s[i][j]=k;
          }
      }
    }
  }
  cout<<"Minimum number of multiplication required :"<<m[1][n-1]<<endl;
}
int main()
{
  int n,a[100];
  cout<<"Enter number of matrices :"<<endl;
  cin>>n;
  cout<<"Enter Dimension: "<<endl;
  for(int i=0;i<=n;i++)
    cin>>a[i];
  parenthesis(a,n);
}
