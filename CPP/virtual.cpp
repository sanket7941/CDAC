#include<iostream>

using namespace std;
class base
{
	public:
	virtual void print()
		{
			cout<<" print base class"<<endl;
		}

		virtual void show()
		{
			cout<<"show base class"<<endl;
		}
};

class der: public base
{
	public:
		void print()
		{
			cout<<" print derive class"<<endl;

		}

		void show()

		{
			cout<<" show  derive class"<<endl;
		}

};

int main()
{
	base *bptr;

	der d;
	bptr = &d;

	bptr->print();

	bptr->show();

/*
	der *dptr;
	base b;
	dptr=&b;
	dptr->print();
	dptr->show();
*/

}
