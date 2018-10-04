package program;

import java.util.Scanner;

import mobilePlan.Plan;

public class Main {

	public static void main(String[] args) 
	{
		int a,b,c;
		Scanner x = new Scanner(System.in);
		System.out.println("enter the your plan details");
		System.out.println("select your plan \n A=1 \n B=2 \n c=3");
		a=x.nextInt(); 
		System.out.println("enter time of call");
		b=x.nextInt();
		System.out.println("enter total number of SMS");
		c=x.nextInt();
		System.out.println("****************************");
		Plan A = new Plan(a,b,c);
		A.Bill();
				
	}

}
