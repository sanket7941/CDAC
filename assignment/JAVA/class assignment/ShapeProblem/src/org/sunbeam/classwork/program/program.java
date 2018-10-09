package org.sunbeam.classwork.program;
import org.sunbeam.classwork.shape.*;
import java.util.Scanner;

public class program {

	public static void main(String[] args) {

		int choice = 0;
		System.out.println("1.Circle");
		System.out.println("2.Rectangle");
		Scanner sc = new Scanner(System.in);
		choice = sc.nextInt();
		Shape s = Shapefactory.getInstence(choice);
		acceptRecord(s);

	}

	private static void acceptRecord(Shape s) {

		Rectangle rectangle = null;
		Circle circle = null;
		if (s instanceof Rectangle) 
		{

			rectangle = (Rectangle) s;
			rectangle.setBreadth();
			rectangle.setLength();
			rectangle.calculateArea();
			System.out.println("Rectanglr AREA" + rectangle.getArea());

		} else {
			circle = (Circle) s;
			circle.setRadius();
			circle.calculateArea();
			System.out.println("Circle Area:" + circle.getArea());
		}
	}
}