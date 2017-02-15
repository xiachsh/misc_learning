package myJDKTest;

import java.util.*;
import java.io.*;

import org.junit.Test;
import org.junit.Ignore;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;



public class FileReaderTest 
{

	public static final int SIZE = 4096;
	@Test
	public void FileReaderTest() throws IOException,FileNotFoundException
	{
		int offset = 0;
		int length = SIZE;
		File f = new File("/etc/passwd");
		if (!f.exists())
		{
			System.out.println("File /etc/passwd not exists");
			System.exit(-1);
		}
		char [] buffer = new char [SIZE];
		FileReader fReader = new FileReader(f);
		
		int size = 0;
		while ((size=fReader.read(buffer,offset,length)) != -1 )
		{
			offset += length;
			if (size != length)break;
		}
		fReader.close();
		
	}



}
