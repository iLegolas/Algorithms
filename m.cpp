#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void printParenthesis(int i, int j, int n,vector <vector<int>> bracket, char &name)
{
    // If only one matrix left in current segment
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i,bracket[i][j], n, bracket, name);
    printParenthesis(bracket[i][j] + 1, j, n, bracket, name);
    cout << ")";
}
void parenthesis(int a[],int n)
{
  int m[n][n]={0},i,j,d,q;
  vector <vector<int>> s(n,vector <int> (n,0));
  for(d=1;d<n-1;d++)
  {
    for(i=1;i<n-d;i++)
    {
      j=i+d;
      m[i][j] = INT_MAX;
      for(int k=i;k<j;k++)
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
  char name = 'A';

    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n-1, n,s, name);
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
  parenthesis(a,n+1);
}
