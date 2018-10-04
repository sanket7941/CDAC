package Main;

import java.util.Scanner;

import org.sunbeam.desd.Bank.fixedDeposit;

public class Main {

	public static void main(String[] args) 
	{
		Scanner x =new Scanner(System.in);
		
		fixedDeposit FD = new fixedDeposit();
		System.out.println("enter the amount to deposite");
		FD.setAmount(x.nextDouble());
		
		System.out.println("enter the time in year");
		FD.setYear(x.nextInt());
		
		FD.intrestValue();
		System.out.println("deposited amount :: " +FD.getAmount());
		System.out.println("number of year :: "+FD.getYear());
		System.out.println("compund intrest :: "+FD.getCompoundIntrest());

	}

}
