/*
Q.3 Create a class called Date that includes three instance
variables—a month (type int), a day (type int) and a year (type
int). Provide a constructor that initializes the three instance
variables and assumes that the values provided are correct.
Provide a set and a get method for each instance
variable. Provide a method displayDate that displays the month,
day and year separated by forward
slashes (/).
Write a test application named DateTest that demonstrates class
Date’s capabilities.*/
import java.util.Scanner;
class Date
{
  private int day,month,year;

  Date()
  {
    this.day =01;
    this.month=01;
    this.year= 2000;
  }
// settter methods
        void setday(int a )
        {
          this.day = a;
        }
        void setMonth(int b)
        {
          this.month = b;
        }
        void setYear(int c)
        {
          this.year = c;
        }

// getter method
        int setday( )
        {
          return this.day;
        }
        int setMonth()
        {
          return this.month;
        }
        int setYear()
        {
          return this.year;
        }
        // show date
        void showDate()
        {
          System.out.println(day+"/"+month+ "/"+year);
        }
}
class Main
{
  public static void main(String[] args)
  {
    Date d1 = new Date(); // Createat instance

    Scanner x = new Scanner(System.in);

    System.out.println("enter the day ");
    int day = x.nextInt();
    if(day >=1 && day<=31)
    {
    d1.setday(day);
    }
    else
    {
    System.out.println("enter proper date");
    }

    System.out.println("enter the month number ");
    int month = x.nextInt();
    if(month >=1 && month <= 12)
    {
      d1.setMonth(month);
    }
    else
    {
      System.out.println("enter proper month");
    }

    System.out.println("enter the year ");
    int year = x.nextInt();
    if(year >1901 && year < 2100)
    {
    d1.setYear(year);
    }
    else
    {
      System.out.println("enter proper year");
    }
    d1.showDate();


  }
}
