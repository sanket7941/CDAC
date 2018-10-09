package org.sunbeam.classwork.program;
import org.sunbeam.classwork.shape.*;
import java.util.Scanner;

public class Shapefactory {

	public static Shape getInstence(int choice) 
	{
		Shape s= null;
		switch (choice) {
		case 1:
			s= new Circle();
			s.calculateArea();
			break;

		case 2:
		  s= new Rectangle();
		  s.calculateArea();
		   break;
		default:
			System.out.println("Invalid");
			break;
		}

		return s;
	
	}
}
