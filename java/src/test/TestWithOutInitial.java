package test;
import java.io.*;


public class TestWithOutInitial
{
	public void pupAge()
	{
//		int age;
		int age = 0;
		age = age + 7;
		System.out.println("puppy Age is :" + age);
	}
	public static void main (String[] args)
	{
		TestWithOutInitial t = new TestWithOutInitial();
		t.pupAge();

	}

}
