package org.sunbeam.classwork;

abstract class Shape 
{
	protected double area;
	
	
	
	public Shape(double area) 
	{
		super();
		this.area = area;
	}
	

	public double getArea() {
		return area;
	}


	abstract double area();
	
//	abstract String toString();
		
	
}

class Circle extends Shape
{
	double radius;
	
	
	public Circle(double area,double radius) {
		super(area);
		this.radius = radius;
	}
	
	
	public double getRadius() {
		return radius;
	}


	double area()
	{
		return Math.PI * Math.pow(radius, 2);
	}


	@Override
	public String toString()
	{
		return "Circle [radius=" + radius + "Area =" + area() + "]";
	}

}

class Rectangle extends Shape
{
	double length;
	double bredth;
	
	public Rectangle(double area, double length, double bredth)
	{
		super(area);
		this.length = length;
		this.bredth = bredth;
	}
	
	
	public void setLength(double length) {
		this.length = length;
	}


	public void setBredth(double bredth) {
		this.bredth = bredth;
	}


	double area()
	{
		return length*bredth;
	}

	@Override
	public String toString() {
		return "Rectangle [length=" + length + ", bredth=" + bredth + "area()=" + area() + "]";
	}
	
}
	
//*************************************************************************************************

public class Program {

	public static void main(String[] args) 
	{
		Shape s1 = new Circle(0,10);
		Shape s2 = new Rectangle(0, 10, 20);
		
		System.out.println(s1.toString());
		System.out.println(s2.toString());
	}

}
