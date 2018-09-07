#include"iostream"

using namespace std;

int main()
{
	int a=10;
	int &b=a;

	cout<<" a= "<< a<<'\n';
	cout<<" b= "<< b<<'\n';
	
	cout<< " addres a= \n"<< &a;

	cout<< " addres a= \n"<< &b;
}
