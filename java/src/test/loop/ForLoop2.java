package test;

import java.io.*;

public class ForLoop2
{

	public static void main(String[] args)
	{
		Byte[] b_arr = new Byte[100];
		for (Byte i = 0; i < 100; i ++)
		{
			b_arr[i] = i;
		}
	
		for (Byte x : b_arr)
		{
			System.out.print(x + "\t");
		}	
	}
}	
