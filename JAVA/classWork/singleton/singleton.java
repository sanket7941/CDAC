package org.classwork.day5;
class single 
{ 
    // static variable single_instance of type single 
    private static single single_instance = null; 
  
    // variable of type String 
    public String s; 
  
    // private constructor restricted to this class itself 
    private single() 
    { 
        s = "Hello I am a string part of single class"; 
    } 
  
    // static method to create instance of single class 
    public static single getInstance() 
    { 
        if (single_instance == null) 
            single_instance = new single(); 
  
        return single_instance; 
    } 
} 

public class Singleton
{

	public static void main(String[] args)
	{
		// instantiating single class with variable x 
        single x = single.getInstance(); 
  
        // instantiating single class with variable y 
        single y = single.getInstance(); 
  
        // instantiating single class with variable z 
        single z = single.getInstance(); 
  
        // changing variable of instance x 
        x.s = (x.s).toUpperCase(); 
  
        System.out.println("String from x is " + x.s); 
        System.out.println("String from y is " + y.s); 
        System.out.println("String from z is " + z.s); 
        System.out.println("\n"); 
  
        // changing variable of instance z 
        z.s = (z.s).toLowerCase(); 
  
        System.out.println("String from x is " + x.s); 
        System.out.println("String from y is " + y.s); 
        System.out.println("String from z is " + z.s); 

	}

}

