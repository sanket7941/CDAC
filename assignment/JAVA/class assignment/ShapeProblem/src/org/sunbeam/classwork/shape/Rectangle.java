package org.sunbeam.classwork.shape;

import java.util.Scanner;

public final class Rectangle extends Shape {
	
	public Rectangle()
	{
		super(0.0f);
	}
	
	public Rectangle(float area) 
	{
		super(area);
	
	}
	private float length;
	private float breadth;

	public float getLength() {
		return length;
	}

	static Scanner sc = new Scanner(System.in);

	public void setLength() {
		System.out.println("Enter length");
		this.length = sc.nextFloat();
	}

	public float getBreadth() {
		return breadth;
	}

	public void setBreadth() {
		System.out.println("enter breadth");
		this.breadth = sc.nextFloat();
	}

	@Override
	public void calculateArea() {
		System.out.println("cal area");
		area = length * breadth;
		//System.out.println("area" + area);

	}

}
