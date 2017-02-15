package learning;


import java.io.*;
import java.util.*;



public class Base
{
	public static int x = 0 ;
	private static int y = 0;
	
	public void func()
	{
		x = x + 1;
	}
	public static void main(String [] args)
	{
		Base b = new Base();
		b.func();
		System.out.println(b.x);
	}
}
