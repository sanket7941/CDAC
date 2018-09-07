#include<iostream>
using namespace std;

int main()
{
	int x=10,y=0,res=0;

	try 
	{
		if(y==0)
		{
			throw true ;
		}
		else
		{
			res=x/y;
			cout<< "ans"<<res;
		}
	}
	catch(int x)
	{
		cout<<"int";

	}
	catch(float x)
	{
		cout<<"float";

	}
	catch(double x)
	{
		cout<<"double";

	}
	catch(char x)
	{
		cout<<"char";

	}

	catch(bool x)
	{
		cout<<"bool";

	}
}
