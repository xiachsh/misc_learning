package myJDKTest;

import java.util.*;
import java.io.FileWriter;
import java.io.*;

import org.junit.Test;
import org.junit.Ignore;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;

public class FileWriterTest
{
	public static final int FILE_NAME_LENGTH = 1024 ;
	public static final Random r = new Random();
	@Test
	public void TestInit()
	{
		
	}

	@Test
	public void TestInitNonExist()
	{
		char [] buffer = new char [FILE_NAME_LENGTH] ;
		for (int i = 0; i<1024;i++)
			buffer[i] = (char) (65 + r.nextInt(26));
		String s = new String(buffer);
		System.out.println("the FILE name is " + s);	
		try {
			FileWriter fWriter = new FileWriter(s);
		}catch (Exception e)
		{
			assertTrue(e instanceof IOException);
		}
	}


}

