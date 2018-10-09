package org.sunbeam.classwork.shape;

	import java.util.Scanner;

	public final class Circle extends Shape {
		float radius;

		public Circle() 
		{
			this(0.0f);
		}

		public Circle(float radius) {
			super(radius);
			this.radius = radius;
		}

		public float getRadius() {
			return radius;
		}
	    static Scanner sc= new Scanner(System.in);
		public void setRadius()
		{
			System.out.println("Enter Radius");
			this.radius= sc.nextFloat();
		}

		@Override
		public void calculateArea() {
			area = (float) (Math.PI * Math.pow(radius, 2));
			//System.out.println("area:" + area);

		}

	}


