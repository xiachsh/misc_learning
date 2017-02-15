package test;
import java.io.*;


public class TestFinal
{
	private boolean myFlag;
	static double weeks = 9.5;
	protected static final int BOXWIDTH = 43;
	
	public void setWeeks(int a)
	{
		weeks = (double) a;
	}

	public static void main(String [] args)
	{
		TestFinal tF = new TestFinal();
		tF.setWeeks(30);
	}
}
