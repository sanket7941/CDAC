package Main;

import java.util.Scanner;

import Circle.Circle;

public class Main {

	public static void main(String[] args) 
	{
		Scanner x = new Scanner(System.in);
		
		Circle c1 = new Circle();
		System.out.println("enter the radius");
		c1.setRadius(x.nextInt());
		System.out.println("Diameter of circle of circle:: "+c1.getDiameter());
		System.out.println("circumferance of circle :: "+c1.getCircumference());
		System.out.println("diameter of circle :: "+c1.getArea());
		

	}

}
