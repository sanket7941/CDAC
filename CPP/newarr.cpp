#include"iostream"

using namespace std;

int main()
{

	int *x=NULL,i,y;

	cout<<"enter the size of array"<<endl;
	cin>>y;
	
	x=new int [y];
	

	cout<<"enter the elemnts of array"<<endl;
	for(i=0;i<=y;i++)
	{
		cin>>x[i];
	}

	cout<<"the elemnts of array are"<<endl;
	for(i=0;i<y;i++)
	{
		cout<<i  << x[i]<<endl;
	}

	delete [] x;
	
}
