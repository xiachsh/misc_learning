package learning;

import java.io.*;
import java.util.*;


public class StaticCodeBlock
{

	private int data;
	public int GetData()
	{
		return data;
	}
	public void SetData(int val)
	{
		this.data = val;
	}
	static 
	{
		System.out.println(StaticCodeBlock.class + " Loaded");
	}

	public void StaticCodeBlock()
	{
		
	}
	public void func()
	{
		System.out.println("StaticCodeBlock::func");	
	}
}
