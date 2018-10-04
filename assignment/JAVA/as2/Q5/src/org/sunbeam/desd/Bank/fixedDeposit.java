package org.sunbeam.desd.Bank;

public class fixedDeposit 
{
	private double amount;
	private int year;
	private double compoundIntrest;
	
	public fixedDeposit()
	{
		this.amount = 0;
		this.year = 0;
	}

//	getter setter
	public void setAmount(double amount) {
		this.amount = amount;
	}
	public void setYear(int year) {
		this.year = year;
	}
		
	public double getAmount() {
		return amount;
	}

	public int getYear() {
		return year;
	}

	public double getCompoundIntrest() {
		return compoundIntrest;
	}

	//	function for intrest value
	public void intrestValue()
	{
		if(amount == 0 && year == 0 )
		{
			System.out.println("enter the value first");
		}
		else if (year >= 5 )
		{
			double temp = (1+(0.1));
			compoundIntrest= amount*(Math.pow(temp, year));
		}
		else if (amount <=2000 && year >= 2 )
		{
			double temp = (1+(0.05));
			compoundIntrest= amount*(Math.pow(temp, year));
		}
		
		else if (amount >=2000 && amount <=6000 && year >= 2 )
		{
			double temp = (1+(0.07));
			compoundIntrest= amount*(Math.pow(temp, year));
		}
		
		else if (amount >=6000 && year >= 1 )
		{
			double temp = (1+(0.08));
			compoundIntrest= amount*(Math.pow(temp, year));
		}
		
		else 
		{
			double temp = (1+(0.03));
			compoundIntrest= amount*(Math.pow(temp, year));
		}
	}
	
	
	
	

}
