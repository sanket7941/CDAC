package mobilePlan;
public class Plan 
{
	private int plan=0,call,SMS;
	private double amount=0,mounthCharge=0;
	
//	constructor
	public Plan() 
	{
		this(0,0,0);
	}
	public Plan(int plan, int call, int sMS) 
	{
		super();
		this.plan = plan;
		this.call = call;
		this.SMS = sMS;
	}

public void Bill()
	{	
		switch (plan) 
		{
//		======================PLAN A ==================================
case 1:  if(call <= 50) // first 50 call free
		{
			amount=0;
		}
		else if(call <= 100) // 50 to 100 call .5 paise/min
		{
			call= call-50;
			amount= call * 0.50;
		}
		else if (call > 101) // next all call 1 rupee
		{
			call = call - 100;
			amount= 25+(1*call);
		}
		//	for SMS
		double temp = SMS * 1;
		amount= amount + temp;	   //extra amount
		mounthCharge = 199+amount; //total bill
		System.out.println("plan A");
		System.out.println("totalbill "+mounthCharge);
		
		break;
		//======================PLAN B ================================
case 2: 	 if(call <= 70)
		{
			amount=0;
		}
		else if(call <= 150)
		{
			call= call-75;
			amount= call * 0.40;
		}
		else if (call < 150)
		{
			call = call - 150;
			amount= 30+(.80*call);
		}
		//	for SMS
		double temp1 = SMS * 0.75;
		amount= amount + temp1;	   //extra amount
		mounthCharge = 299+amount; //total bill
		System.out.println("plan B");
		System.out.println("totalbill "+mounthCharge);
		
		break;
//		==========================PLAN C ==========================
case 3:  if(call <= 100)
		{
			amount=0;
		}
		else if(call <= 200)
		{
			call= call-100;
			amount= call * 0.30;
		}
		else if (call <200)
		{
			call = call - 200;
			amount= 25+(1*call);
		}
		//	for SMS
		double temp2 = SMS * 0.50;
		amount= amount + temp2;	   //extra amount
		mounthCharge = 399+amount; //total bill
		System.out.println("plan C");
		System.out.println("totalbill "+mounthCharge);
		
		break;
 		
		}
	}
		
}	

	
	
