import java.util.Scanner;
class math
{

      int addition(int x , int y)
      {
        return x + y;
      }

      int subtraction(int x,int y)
      {
        return x - y;
      }

      float division(float x , float y)
      {
          return x/y;
        }

      int multiplication(int x , int y)
        {
          return x*y;
        }
}
class Assignment4
{
  public static void main(String[] args)
  {
    Scanner a = new Scanner(System.in);
    System.out.println("enter two values");

    int num1 = a.nextInt();
    int num2 = a.nextInt();

    math m = new math();

    int p = m.addition(num1,num2);
    System.out.println(p);

  }

}
