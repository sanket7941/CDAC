package org.sunnbeam.desd.main;

import java.util.Scanner;

//import java.util.Scanner;

//import com.sun.org.apache.xalan.internal.xsltc.compiler.Pattern;

public class Program {

	public static void main(String[] args)
	{
		Scanner x =new Scanner(System.in);
		int[] pattern = new int[4];
		
		for (int i = 0; i < pattern.length; i++) 
		{
			pattern[i]= x.nextInt();
		}
		
		for (int i = pattern.length ; i > 0; i--) 
		{
			for (int j = i ; j > 0; j--) 
			{
				
				System.out.print(pattern[j-1]);				
			}
			System.out.println();
		}
			
	}

}
