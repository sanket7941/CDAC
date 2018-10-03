import java.util.Scanner;

	class Invoice
	{
		// fields
			private String 	Partnumber;
			private String 	Description;
			private int 		Quentity;
			private double 	Price;
			private double 	Amt;
// constructer
		Invoice()
		{
			this.Partnumber =" ";
			this.Description=" ";
			this.Quentity = 0;
			this.Price= 0.0;
		}
// settter methods
					void setPartnumber(String a )
					{
						this.Partnumber = a;
					}
					void setDescription(String b)
					{
						this.Description = b;
					}
					void setQuentity(int c)
					{
						this.Quentity = c;
					}
					void setPrice(double d)
					{
						this.Price = d;
					}

					double setInoviceAmount()
					{
						Amt = Price * Quentity;
						return Amt;
					}
		}
///main class
class Program
{
	public static void main(String[] args)
	{
			Invoice I1 = new Invoice(); // crrat instance

			Scanner x = new Scanner(System.in);

			System.out.println("enter the part name");
			String s = x.nextLine();
			I1.setPartnumber(s);

			System.out.println("enter the part description");
			String s1 = x.nextLine();
			I1.setDescription(s1);

			System.out.println("enter the Quentity");
			int s3 = x.nextInt();
			I1.setQuentity(s3);

			System.out.println("enter the Price");
			double s4 = x.nextDouble();
			I1.setPrice(s4);

			System.out.println("total bill to be paid");
			double s5 = I1.setInoviceAmount();
			System.out.println(s5);
	}
}
