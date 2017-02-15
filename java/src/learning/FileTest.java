package myJDKTest;

import java.io.*;
import java.util.*;
import org.junit.Test;
import org.junit.Ignore;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;

public class FileTest
{
	public static Random r = new Random();
	@Test
	public void testDirExists()
	{
		File f = new File("/");
		assertTrue(f.exists());
	}
	@Test
	public void testNotExists()
	{
		char[] intArr = new char [20];
		for (int i = 0; i < 20;i++)
			intArr[i] =(char)(65 + r.nextInt(26));	

		String filePath = new String(intArr);
		File f = new File(filePath);		
		assertFalse(f.exists());
	}
	@Test
	public void testCreate() throws IOException
	{
		char[] intArr = new char [20];
		for (int i = 0; i < 20;i++)
			intArr[i] =(char)(65 + r.nextInt(26));	

		String fileName = new String(intArr);
		String fullPath = "/tmp/" + fileName; 
		File f = new File(fullPath);		
		f.createNewFile();
		assertTrue(f.exists());
	}

}

