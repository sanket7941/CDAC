#include <iostream>
using namespace std;

// swaping function
void swap(int *a, int *b)
{
  int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// searching algo
void searchX(int *x,int n,int key)
{
  int i,flag=0;
  for(i=0;i<=n;i++)
  {
    if(key==x[i])
    {    cout<<"key found at"<<i<<endl;flag++ ;}

  }
  if(flag==0){ cout<<"key not found"<<endl; }
}
void binary(int *x,int n,int key)
{
      int i,mid,flag=0;
      mid=n/2;
      if(mid==key)
      { return 1;}
      if(middle>x)
      {

      }
      else
      {

      }
}

// sorting algo
int bubsort(int *x,int n)
{
  int i,j,k;
  for (k = 0;k < n;k++) {
    for ( i = 0; i < n-1; i++)
     {
       for (j = i; j < n; j++)
       {
         if(x[j]>x[j+1])
         {
           swap(x[j],x[j+1]);
         }
       }
     }
   }
}

void printArr(int *x,int n)
{
  int i;
  for (i = 0; i < n; i++) {
    cout<<x[i]<<endl;
  }
}


int main(int argc, char const *argv[]) {
  cout<<"start of code"<<endl;
  int arr[5]={5,4,3,2,1};
  cout<<"array"<<endl;
  printArr(arr,5);
  bubsort(arr,5);
  cout<<"sorted array"<<endl;
  printArr(arr,5);
  searchX(arr,5,3);
  return 0;
}
