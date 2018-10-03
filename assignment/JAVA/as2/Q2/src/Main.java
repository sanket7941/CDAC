/*Q.2 Create a class called Employee that includes three instance
variables—a first name (type String), a last name (type String)
and a monthly salary (double). Provide a constructor that
initializes the three instance variables. Provide a set and a
set method for each instance variable. If the monthly salary is
not positive, do not set its value. Write a test application
named EmployeeTest that demonstrates class Employee’s
capabilities. Create two Employee objects and display each
object’s yearly salary. Then give each Employee a 10% raise and
display each Employee’s yearly salary again.
*/
import java.util.Scanner;

	class Employee
	{
		private String 	firstName;
		private String 	lastName;
		private double 	salary;

// constructer
		Employee()
		{
			this.firstName =" ";
			this.lastName=" ";
			this.salary= 0.0;
		}
// settter methods
					void setFirstName(String a )
					{
						this.firstName = a;
					}
					void setLastName(String b)
					{
						this.lastName = b;
					}
					void setSalary(double c)
					{
						this.salary = c;
					}

// getter method
          String getFirstName()
          {
            return this.firstName;
          }
          String getLastName()
          {
            return this.lastName;
          }
          double getSalary()
          {
            return this.salary;
          }

  // show all info of Employee
        void showAll()
        {
          System.out.println(firstName);
          System.out.println(lastName);
          System.out.println(salary);
          // System.out.println();
        }
// 10 % hike in salary
        void hikeSalary()
        {
          double temp = salary/10;
          this.salary= salary+temp;
          showAll();
        }
		}

class Main
{
	public static void main(String[] args)
	{
			Employee e1 = new Employee(); // Createat instance
      Employee e2 = new Employee();

			Scanner x = new Scanner(System.in);

      //  Employee 1
			System.out.println("enter the Employee first name");
			String s = x.nextLine();
			e1.setFirstName(s);

			System.out.println("enter the Employee last name");
			String s1 = x.nextLine();
			e1.setLastName(s1);

			System.out.println("enter the salary");
			double s2 = x.nextDouble();
			e1.setSalary(s2);

      // Employee 2

      System.out.println("enter the Employee FIRST name");
			String t = x.nextLine();
			e2.setLastName(t);

			System.out.println("enter the Employee last name");
			String t1 = x.nextLine();
			e2.setLastName(t1);

			System.out.println("enter the salary");
			double t2 = x.nextDouble();
			e2.setSalary(t2);

      // show details of Employee
      System.out.println("Employee 1");
      e1.showAll();

      System.out.println("Employee 2");
      e2.showAll();


		  System.out.println("********************************************");
      System.out.println("salary after 10% hike");
      e1.hikeSalary();

      System.out.println("salary after 10% hike");
      e2.hikeSalary();


		}
}
