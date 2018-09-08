#include<iostream>

using namespace std;

class food :egg
{
	public:
		int	a;
		food()

		{
			this->a=10;
			cout<< " the aroma of Jevan is awosome"<< a<<endl;
		}


		~food()
		{
		//	cout<< " dtor food";
			this->a=0;
		}
};

class NonVeg : public food
{
	public:
		int b;
	NonVeg()
	{
		this->b=20;

		cout<< "mutton te kay ast"<<b<<endl;
	}
	~NonVeg()
	{}
};

class Veg : public food

{
	public:
		int c;
	Veg()
	{
		this->c=30;
		cout<< " i love cheeeeeees"<<c<<endl;
	}
	~Veg()
	{}
};

class egg : public Veg , public NonVeg
{
	public:
		int d;
		egg()
		{
			this->d=40;
			cout<< " ande ka funda"<<d<<endl;
		}
		~egg(){}
};


int main()

{
	food f;

	cout<<"\n";
	NonVeg Fn;

	cout<<"\n";
	Veg Fv;

	cout<<"\n";
	egg eg;


	return 0;
}
