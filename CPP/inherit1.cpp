#include<iostream>

using namespace std;

class food
{
	private:
		int	a;
	public:
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
	private:
		int b;
	public:
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
	private: 
		int c;
	public:
		Veg()
		{
			this->c=30;
			cout<< " i love cheeeeeees"<<c<<endl;
		}
		~Veg()
		{}
};
