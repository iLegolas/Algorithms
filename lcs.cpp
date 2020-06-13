/* Dynamic Programming implementation of LCS problem */
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs( char *X, char *Y, int m, int n )
{
int L[m+1][n+1];
for (int i=0; i<=m; i++)
{
	for (int j=0; j<=n; j++)
	{
	if (i == 0 || j == 0)
		L[i][j] = 0;
	else if (X[i-1] == Y[j-1])
		L[i][j] = L[i-1][j-1] + 1;
	else
		L[i][j] = max(L[i-1][j], L[i][j-1]);
	}
}
int index = L[m][n];
cout<< index<<endl;

char lcs[index+1];
lcs[index] ='\0'; // Set the terminating character

int i = m, j = n;
while (i > 0 && j > 0)
{
	if (X[i-1] == Y[j-1])
	{
		lcs[index-1] = X[i-1]; // Put current character in result
		i--; j--; index--;	 // reduce values of i, j and index
	}
	else if (L[i-1][j] > L[i][j-1])
		i--;
	else
		j--;
}

// Print the lcs
cout << "LCS of " << X << " and " << Y << " is " << lcs<<endl;

}

/* Driver program to test above function */
int main()
{
//char X[] = "AGGTAB";
char Y[100];
char X[100];
  cin>>X;
	cin>>Y;

int m = strlen(X);
int n = strlen(Y);
lcs(X, Y, m, n);
return 0;
}
