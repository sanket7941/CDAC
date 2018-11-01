package org.sunbeam.classWork.methodOverriding;

//parent class
 class Food
{
	void show()
	{
		System.out.println("food class");
	}
}
//base class

 class VadaPav extends Food
{
	void show()
	{
		super.show();
		System.out.println("VadaPav class");
	}
}

public class Main {

	public static void main(String[] args) {
//		Food f =new Food();
//		f.show();
		Food v =new VadaPav();
		v.show();
	}

}
