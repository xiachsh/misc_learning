package learning;

import java.io.*;
import java.util.*;



public class Derived extends Base
{
	public void func()
	{
		x = x + 2;
	}	


	public static void main(String [] args)
	{
		Derived d = new Derived ();
		d.func();
		
		System.out.println(d.x);
		//System.out.println(d.y);

	}
}
