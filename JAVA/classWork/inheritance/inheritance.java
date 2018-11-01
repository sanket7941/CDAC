package org.classwork.day5;

class A
{
	private int num1;
	private int num2;
	public A(int num1, int num2)
	{

		this.num1 = num1;
		this.num2 = num2;
	}
	void show()
	{
		System.out.println(num1);
		System.out.println(num2);
	}

}

class B extends A
{
	private int num3;
	private int num4;

	public B(int num1, int num2,int num3, int num4)
	{
		super(num1,num2);
		this.num3 = num3;
		this.num4 = num4;
	}

	void show()
	{
		super.show();
		System.out.println(num3);
		System.out.println(num4);
	}

}
class inheritance
{
	public static void main(String[] args)
	{
		B b = new B(1,2,3,4);
		b.show();		
	}
}
