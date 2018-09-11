#include<typeinfo>
#include<iostream>
using namespace std;
//namespace NRTTI
//{
	class Shape
	{
	protected:
		double area;
		double perimeter;
	public:
		Shape()
		{
			this->area=0;
			this->perimeter=0;
			cout<<"inside shape class ctor"<<endl;
		}

		// pure virtual function
		virtual void AcceptInput()=0;

		// polymorphic class
		virtual void PrintOutput()
		{
		}
		virtual void CalculateArea()
		{
		}
		virtual void CaluclatePerimeter()
		{
		}

		virtual ~Shape()
		{
			this->area=0;
			this->perimeter=0;
			cout<<"inside shape class dtor"<<endl;
		}
	};// end of shape class

	class Circle: public Shape
	{
		private:
			double radius;
		public:
			Circle()
			{
				this->radius=0;
				cout<<"inside ctor of circle class"<<endl;
			}
			void AcceptInput()
			{
				cout<<"Enter Radius :: ";
				cin>>this->radius;
			}
			void PrintOutput()
			{
				cout<<"this->radius:: "<<this->radius<<endl;
				cout<<"this->area:: "<<this->area<<endl;
				cout<<"this->perimeter:: "<<this->perimeter<<endl;
			}
			void CalculateArea()
			{
				this->area=3.142 *  this->radius * this->radius;
			}
			void CaluclatePerimeter()
			{
				this->perimeter= 2* 3.142* this->radius;
			}

			~Circle()
			{
				this->radius=0;
				cout<<"inside dtor of circle class"<<endl;
			}

	};//end of class
	class Rectangle : public Shape
	{
		private:
			double  l, b;
		public:
			Rectangle()
			{
				this->l=0;
				this->b=0;
				cout<<"inside ctor of Rectangle class"<<endl;
			}

			void AcceptInput()
			{
				cout<<"Enter l :: ";
				cin>>this->l;
				cout<<"Enter b :: ";
				cin>>this->b;

			}
			void PrintOutput()
			{
				cout<<"this->l:: "<<this->l<<endl;
				cout<<"this->b:: "<<this->b<<endl;
				cout<<"this->area:: "<<this->area<<endl;
				cout<<"this->perimeter:: "<<this->perimeter<<endl;
			}
			void CalculateArea()
			{
				this->area=this->l * this->b;
			}
			void CaluclatePerimeter()
			{
				this->perimeter= 2* (this->l + this->b);
			}
			~Rectangle()
			{
				this->l=0;
				this->b=0;
				cout<<"inside dtor of Rectangle class"<<endl;
			}
	}; //end of class Rectangle
//}//end of namespace

//using namespace NRTTI;

int MenuChoice();
int main()
{
	//Shape obj;  // Shape abstract class
	Shape *objShape=NULL;
	int choice;

	do
	{
		choice= MenuChoice();
		switch(choice)
		{
			case 1:// circle
					objShape= new Circle();
				break;
			case 2 :// rectangle
					objShape= new Rectangle();
				break;
		}

		const type_info& info = typeid(*objShape);
		cout << "data type ::"<< info.name() << endl;


		if(objShape!=NULL)
		{
			objShape->AcceptInput();
			objShape->CalculateArea();
			objShape->CaluclatePerimeter();
			objShape->PrintOutput();

			delete objShape;
			objShape=NULL;
		}




	}while(choice!=0);

	return 0;
}
int MenuChoice()
{
	int choice;
	cout<<"1. Circle \n 2. Rectangle \n 0. Exit"<<endl;
	cout<<"enter Your choice :: ";
	cin>>choice;
	return choice;
}
