#include <iostream>

using namespace std;
#define SIZE 8
#define SWAP(a,b) {int t=a;a=b;b=t; }


void printArr(int *x,int n);
void mergeSort(int *arr,int left,int right);
void merge(int *arr,int left,int mid,int right);
// main

int main()
{
  int arr[SIZE]={5,1,8,3,7,4,6,2};
  cout <<"array"<<endl;
  printArr(arr,SIZE);
  mergeSort(arr,0,SIZE-1);
  cout << "sorted array" << endl;
  printArr(arr,SIZE);

  return 0;
}

// printing function
void printArr(int *x,int n)
{
  int i;
  for (i = 0; i < n; i++) {
    cout<<x[i]<<endl;
  }
}
// sorting algo
void mergeSort(int *arr,int left,int right)
{
  if(left < right)
  {
    int mid = (left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
  }
}

void merge(int *arr,int left,int mid,int right)
{
  int i=left;
  int j=mid+1;
  int size = right - left+1;
  int k = 0;

  int *temp = new int[size];

  while(i <=mid && j<= right)
  {
    if(arr[i] < arr[j] )
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  while (i <= mid)
    temp [k++] = arr[i++];

  while (j <= mid)
   temp[k++] = arr[j++];

  i = left;
  k=0;
  while( i <= right )
  { arr[i++] = temp[k++];}

  // free the memory
  delete temp;
  temp = NULL;
}
