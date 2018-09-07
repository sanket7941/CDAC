#include"iostream"
using namespace std;
int food(int,int);
int food(int,float);
int food(float,int);

int main()
{
  food(1,1);
  food(1,2.2f);
  food(1.3f,4);
  food(1,2);
  return 0;
}

int food(int,int)
{
  cout<<"int int";
  return 0;
}
int food(int,float)
{
  cout<<" int float";
  return 0;
}
int food(float,int)
{
  cout<<"float int";
  return 0;
}
