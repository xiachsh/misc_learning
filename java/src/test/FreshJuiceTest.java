package test;

import java.io.*;

class FreshJuice
{
	enum FreshJuiceSize { SMALL,MEDIA,LARGE};
	FreshJuiceSize size;
} 

public class FreshJuiceTest 
{
	public static void main(String[] args)
	{
		FreshJuice juice = new FreshJuice();
		juice.size = FreshJuice.FreshJuiceSize.SMALL;
		
		System.out.println(juice.size);
	}
}
