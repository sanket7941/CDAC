import java.util.Scanner;

	class Invoice
	{
		String 	Partnumber;
		String 	Description;
		int 		Quentity;
		double 	Price;
		double 	Amt;
// constructer
		Invoice()
		{
			this.Partnumber =" ";
			this.Description=" ";
			this.Quentity = 0;
			this.Price= 0.0;
		}
// gettter methods
					void getPartnumber(String a )
					{
						this.Partnumber = a;
					}
					void getDescription(String b)
					{
						this.Description = b;
					}
					void getQuentity(int c)
					{
						this.Quentity = c;
					}
					void getPrice(double d)
					{
						this.Price = d;
					}

					double getInoviceAmount()
					{
						Amt = Price * Quentity;
						return Amt;
					}
		}

class Program
{
	public static void main(String[] args)
	{
			Invoice I1 = new Invoice(); // crrat instance

			Scanner x = new Scanner(System.in);

			System.out.println("enter the part name");
			String s = x.nextLine();
			I1.getPartnumber(s);

			System.out.println("enter the part description");
			String s1 = x.nextLine();
			I1.getDescription(s1);

			System.out.println("enter the Quentity");
			int s3 = x.nextInt();
			I1.getQuentity(s3);

			System.out.println("enter the Price");
			double s4 = x.nextDouble();
			I1.getPrice(s4);

			System.out.println("total bill to be paid");
			double s5 = I1.getInoviceAmount();
			System.out.println(s5);
	}
}
