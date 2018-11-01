package multiDimensional;

import java.util.Scanner;

public class array {

	public static void main(String[] args)
	{
		Scanner x = new Scanner(System.in);

		
//		single dimensional array
//		int size =x.nextInt();
		int[] arr0 = new int[4];
		System.out.println("enter the element of array");
		for (int i = 0; i < arr0.length; i++)
		{
			arr0[i] = x.nextInt();  
		}
		
		for (int j = 0; j < arr0.length; j++)
		{
				System.out.println(arr0[j]+" "+j);
		}
		
	/*
//		multiDimensional array
		int arr[][]= new int [][] {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
		for (int i = 0; i < arr.length; i++) 
		{
			for (int j = 0; j < arr[i].length; j++)
			{
				System.out.print(arr[i][j]);
								
			}
			System.out.println();
			
		}
//		ragged array
		int arr1[][]= new int [][] {{1},{4,5},{7,8,9},{1,2,3,9}};
		for (int i = 0; i < arr.length; i++) 
		{
			for (int j = 0; j < arr1[i].length; j++)
			{
				System.out.print(arr[i][j]);
								
			}
			System.out.println();
			
		}
*/
	}

}
