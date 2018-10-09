package org.sunbeam.classwork.shape;

import java.util.Scanner;

public abstract class Shape 
{
	protected float area;

	public Shape(float area) 
	{
		this.area = area;
	}
	public abstract void calculateArea();

	public float getArea() {
		return this.area;
	}
	
}

