#include<iostream>

using namespace std;

int main()
{
	int *x=NULL;

	x= new int;

	cout<<"enter the *x::"<<endl;

	cin>>*x;

	cout<<"*x ::"<<endl;
	cout<<"*x = "<<*x<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"&x = "<<&x<<endl;

	delete x;

	x=NULL;

	cout<<" mem is free"<<endl;
	return 0;
}


