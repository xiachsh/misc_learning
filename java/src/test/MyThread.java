package test;

import java.io.*;

public class MyThread extends Thread
{
	public MyThread()
	{
		super();
	}

	public void run()
	{
		for (int i = 0; i < 5;i++)
		System.out.print(getId() +"\n");
		System.out.println("");
	}

	public static void main(String[] args)
	{
		MyThread[] t_arr = new MyThread[5];
		for  (int i = 0;i < 5;i++)
		{
			t_arr[i] = new MyThread();
			t_arr[i].start();
		}
	}
}
