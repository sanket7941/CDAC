/* Accept one integer number from command line and provide the
following functionalities
Sum of digits. [e.g. for 1234 , 1 + 2 + 3 + 4 = 10]
*/

import java.util.Scanner; // import scanner package

class Assignment3
{
  public static void main(String[] args)
  {

    Scanner x =new Scanner(System.in);
    System.out.println("Enter the value");

    int i = x.nextInt();  // scanf the value
    int a1,a2,a3,a4,x1;   // used in fun 1
    int x2,rem=0,rev=0;       //used in 2 function


    System.out.println(i);
    //************  print face value **************
    // 1) Sum of digits. [e.g. for 1234 , 1 + 2 + 3 + 4 = 10]
    System.out.println("print the face value");

    x1=i;
    a1 = x1 / 1000; //4 digit
    x1 = x1 % 1000; //shift
    a2= x1 / 100;
    x1 =x1 % 100;
    a3= x1 / 10;
    a4= x1 % 10;
    System.out.println("face value "+a1 +" "+a2+" "+a3+" "+a4);
    System.out.println("addition of face value ="+(a1+a2+a3+a4));

    // **************** REV the number **************
    // 2)Reverse number [e.g. for 1234 ,4321]
    System.out.println("print the reverse value");

    x2=i;

    while(x2 != 0)
    {
        rem = x2%10;
        rev = rev * 10+rem;
        x2=x2/10;
    }
    System.out.println("reverse number " +i+"="+ rev);

    //3)Check weather given number is palindrome or not.
  }
}
