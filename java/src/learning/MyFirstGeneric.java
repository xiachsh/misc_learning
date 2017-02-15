package learning;

import java.io.*;
import java.util.*;



public class MyFirstGeneric<T> 
{

	public void print_element(T t)
	{
		if (t instanceof String)
		{
			System.out.println(t);	
		}
		else
		{
			System.out.println(t.toString());
		}
	}

	public static void main(String [] args)
	{
		String s = new String("hello world");
		MyFirstGeneric<String> myFirstGeneric = new  MyFirstGeneric<String>();
		myFirstGeneric.print_element(s);	
			
		Integer x = new Integer(100);
		MyFirstGeneric<Integer> myFirstGeneric2 = new  MyFirstGeneric<Integer>();
                myFirstGeneric2.print_element(x);

	}
}
