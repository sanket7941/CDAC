#include<iostream>

using namespace std;

#define SIZE 5

// 

class stack
{
	private:
	int arr[SIZE];
	int ptr;
	
	public:
	// Ctor
	stack()
	{
		for(int i=0;i< SIZE;i++)
			arr[i] = 0;

		ptr=-1;
	}
	
	bool stackEmpty(void)
	{	return (ptr == -1); }

	bool stackFull(void)
	{	return (ptr == SIZE-1); }


	void pushElement(int data)
	{
		ptr++;
		arr[ptr] = data;
	}

	void popElement(void)
	{	ptr--;	}

	int peekElement(int pos)
	{	return(arr[pos]);	}

	void Display()
	{

		for(int i=0;i<= ptr;i++)
		{		
			cout<<"element ->"<<i+1<<" =>"<<arr[i]<<endl;
		}
	}

};

int main()
{
	stack s;
	// add ele to stack
	s.pushElement(10);
	s.pushElement(20);
	s.pushElement(30);
	s.Display();
	cout<<" remove element"<<endl<<endl;

	s.popElement();
	s.Display();

	cout<<

	return 0;
}


