package learning;


import java.util.*;
import java.io.*;


public class BubbleSort
{
	public static final int LEN = 16;
	public static void anotherSwap(int x,int y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}

	public static void swapArrEle(int [] arr,int x,int y)
	{
			int tmp = arr[x] ;
			arr[x] = arr[y];
			arr[y] = tmp;
	}
	public static void main(String[] args)
	{
		
		int i = 0, j = 0;
		int [] arr = new int[LEN];
		Random r = new Random();
		for (i = 0; i < LEN;i++)
		arr[i] = r.nextInt(20);	
		for ( i = 0; i < LEN;i++)
			System.out.print(arr[i] + "\t");
		System.out.println("");

		for (i = 0; i < LEN; i++)
		{
			for (j = i+1;j < LEN ; j++)
			if (arr[i] > arr[j]) 
			{
			//	anotherSwap(arr[i],arr[j]);
				swapArrEle(arr,i,j);
			/*
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			*/
			}
		}
		for ( i = 0; i < LEN;i++)
			System.out.print(arr[i] + "\t");
		System.out.println("");
	
	}
}
