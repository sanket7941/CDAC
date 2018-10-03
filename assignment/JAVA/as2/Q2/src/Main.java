/*Q.2 Create a class called Employee that includes three instance
variables—a first name (type String), a last name (type String)
and a monthly salary (double). Provide a constructor that
initializes the three instance variables. Provide a set and a
get method for each instance variable. If the monthly salary is
not positive, do not set its value. Write a test application
named
EmployeeTest
that
demonstrates
class
Employee’s
capabilities. Create two Employee objects and display each
object’s yearly salary. Then give each Employee a 10% raise and
display each Employee’s yearly salary again.
*/
import java.util.Scanner;

	class Employee
	{
		String 	firstName;
		String 	lastName;
		double 	salary;
		double 	Amt;
// constructer
		Employee()
		{
			this.firstName =" ";
			this.lastName=" ";
			this.salary= 0.0;
		}
// gettter methods
					String getfirstName(String a )
					{
						return this.firstName= a;
					}
					String getlastName(String b)
					{
						return this.lastName = b;
					}
					double getPrice(double d)
					{
						return this.salary = d;
					}

		}

class Main
{
	public static void main(String[] args)
	{
			Employee e1 = new Employee(); // Createat instance
      Employee e2 = new Employee();

			Scanner x = new Scanner(System.in);

			System.out.println("enter the Employee first name");
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
