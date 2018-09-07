#include<iostream>

using namespace std;

namespace Epy
{
	class py
	{
		private:
			int x,y,ans;

		public:
			void getdata(int x, int y)
			{
				cout<< " enter the 2 value::";
				cin>> x>>y;
				ans=(x*x)+(y*y);
			}

			void putdata()
			{
				cout<<this->x<<'\t'<<this->y;
		//		cout<< "\n the ans is:: "<<ans;
			}

			// constructor
			py()
			{
				this->x=10;
				this->y=5;
			}

			py(int x ,int y)
			{
				this->x=x;
				this->y=y;
			}
			// destructor
			~py()
			{
				this->x=0;
				this->y=0;
				cout<<"int Dtor";
			}


	};// end of class
}// end of namespace
int main()
{
	using namespace Epy;
//	py p;
	py p;
	
//	p.getdata(10,5);
	p.putdata();

return 0;
}

