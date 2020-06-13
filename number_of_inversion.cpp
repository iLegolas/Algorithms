/***************************************************************************
	Name:Maurya Sujeet
	Roll no.:17BCS016
	LAB:A2
	code:To Find number of inversions in an array of n elements  .
****************************************************************************/
#include<iostream>
using namespace std;
int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int count = 0;

  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      count = count + (mid - i);
    }
  }
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  return count;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
  int mid,count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    count  = mergeSort(arr, temp, left, mid);
    count += mergeSort(arr, temp, mid+1, right);
    count += merge(arr, temp, left, mid+1, right);
  }
  return count;
}

int temp(int arr[], int size)
{
    int *temp = (int *)malloc(sizeof(int)*size);
    return mergeSort(arr, temp, 0,size - 1);
}

int main()
{
  int arr[100],n;
  cout<<"Enter number of elements: "<<endl;
  cin>>n;
  cout<<"Enter number of elements : "<<endl;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<" Number of inversions are "<<temp(arr, n)<<endl;
  return 0;
}
