/*Q.4 (Target-Heart-Rate Calculator) While exercising, you can use
a heart-rate monitor to see that your heart rate stays within a
safe range suggested by your trainers and doctors. According to
the formula for the American Heart Association(AHA),
calculating your maximum heart rate in beats per minute is 220
minus your age in years. Your target heart rate is a range
that’s 50–85% of your maximum heart rate. [Note: These formulas
are estimates provided by the AHA. Maximum and target heart
rates may vary based on thehealth, fitness and gender of the
individual. Always consult a physician or qualified health care
professional before beginning or modifying an exercise program.]
Create a class called HeartRates. The class attributes should
include the person’s first name, last name and date of birth
(consisting of separate attributes for the month, day and year
of birth). Your class should have a constructor that receives
this data as parameters. For each attribute provide set and get
methods. The class also should include a method that calculates
and returns the person’s age (in years), a method that
calculates and returns the person’s maximum heart rate and a
method that calculates and returns the person’s target
heart rate. Write a Java application that prompts for the
person’s information, instantiates an object of class HeartRates
and prints the information from that object—including the
person’s first name, last name and date of birth—then calculates
and prints the person’s age in (years), maximum heart
rate and target-heart-rate range.
import java.util.Scanner;*/
import java.util.Scanner;
class HeartRates
{
    String firstName;
    String lastName;

    int maxHeartBeat;
  // settter methods
            void setFirstName(String a )
            {
              this.firstName = a;
            }
            void setLastName(String b )
            {
              this.lastName = b;
            }
    // getter method
            String setFirstName( )
            {
              return this.firstName;
            }
            String setLastName( )
            {
              return this.lastName;
            }
    // show all information
    void showAll()
    {
      System.out.println("firstName = "+firstName);
      System.out.println("lastName = "+lastName);
      System.out.println("max heart beat = "+maxHeartBeat);

    }
    int getHeartBeat(int a)
    {
      this.maxHeartBeat= 220-a;
      return maxHeartBeat;
    }
    
}

// CLASS for DATE of birth
class Date
{
  protected int day,month,year;
  Date()//
  {
    this.day =0;
    this.month=0;
    this.year= 0;
  }
// settter methods
        void setday(int a )
        { this.day = a; }
        void setMonth(int b)
        { this.month = b;}
        void setYear(int c)
        { this.year = c; }
// getter method
        int setday( )
        { return this.day; }
        int setMonth()
        { return this.month; }
        int setYear()
        { return this.year;  }

        int Age()
        {
          int age = 2018-year;
          return age;
        }
        // show date
        void showDate()
      { System.out.println(day+"/"+month+ "/"+year); }
}

class program
{
    public static void main(String[] args)
    {

      Date d1 = new Date(); // Createat instance for DOB
      HeartRates H = new HeartRates(); // Createat instance for DOB

      Scanner x = new Scanner(System.in);
      // enter the personal details
      System.out.println("enter the First name");
			String s = x.nextLine();
			H.setFirstName(s);

			System.out.println("enter the Last Name");
			String s1 = x.nextLine();
			H.setLastName(s1);

      // enter the DOB
      System.out.println("enter the Date of birth");
      System.out.println("enter the day ");
      int day = x.nextInt();
      if(day >=1 && day<=31)
      {   d1.setday(day);    }
      else
      {      System.out.println("enter proper date");      }

      System.out.println("enter the month number ");
      int month = x.nextInt();
      if(month >=1 && month <= 12)
      {        d1.setMonth(month);      }
      else
      {        System.out.println("enter proper month");      }

      System.out.println("enter the year ");
      int year = x.nextInt();
      if(year >1901 && year < 2019)
      {      d1.setYear(year);      }
      else
      {        System.out.println("enter proper year");      }

       int age = d1.Age();
       int max = H.getHeartBeat(age);

// print all information
      H.showAll();



    }// end of main
}// end of program class
