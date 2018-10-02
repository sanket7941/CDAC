// assignment 5 with menu driven
import java.util.Scanner;

class Assignment5
{
  public static void main(String[] args)
  {
    Scanner a = new Scanner(System.in);
    System.out.println("enter two values");

    int num1 = a.nextInt();
    int num2 = a.nextInt();
     int choice;

    math m = new math();// creat object of math class

    do{
    System.out.println("======== menu ===========");
    System.out.println("1 addition");
    System.out.println("2 subtraction");
    System.out.println("3 division");
    System.out.println("4 multiplication \n");
    System.out.println("0 exit");
    System.out.println("enter choice");
    choice = a.nextInt();

    switch (choice)
     {
            case 1:  int p = m.addition(num1,num2);
                      System.out.println(p);
                     break;
            case 2:  int q = m.subtraction(num1,num2);
                      System.out.println(q);
                     break;
            case 3:  float r = m.division(num1,num2);
                      System.out.println(r);
                     break;
            case 4:  int s = m.multiplication(num1,num2);
                      System.out.println(s);
                     break;
            default: System.out.println(" thank you :)");
                     break;
      }//end switch
  }while (choice !=0);//end while

}// end main class

}// end

class math
{
     // method for addition
      int addition(int x , int y)
      {
        return x + y;
      }
      // method for subtraction
      int subtraction(int x,int y)
      {
        return x - y;
      }

      // method for division
      float division(float x ,float y)
      {
        return x/y;
      }
      // method for multiplication
      int multiplication(int x , int y)
      {
        return x*y;
      }
}
