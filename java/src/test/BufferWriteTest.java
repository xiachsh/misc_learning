package test;

import java.io.*;
import java.nio.*;
import java.nio.channels.FileChannel;


public class BufferWriteTest
{
	public static final int SIZE = 1024 * 1024;
	public static void main(String [] args) throws FileNotFoundException,IOException
	{
		int count = Integer.parseInt(args[0]);
		FileChannel channel = new FileOutputStream("./file2").getChannel();
		String s = "Please input your comments here\n";
		System.out.println("Before bBuffer allocate");
		ByteBuffer bBuffer = ByteBuffer.allocateDirect(count * SIZE * s.length());
		System.out.println("after bBuffer allocate");
		
		for (int i = 0 ; i<count * SIZE;i++)
			bBuffer.put(s.getBytes());	
		bBuffer.flip();

		while(bBuffer.hasRemaining())
		{
			channel.write(bBuffer);
		}
	
		channel.close();
	}
}
