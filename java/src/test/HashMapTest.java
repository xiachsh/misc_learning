package learning;

import java.io.*;
import java.util.*;


public class HashMapTest
{
	

	public static void main(String[] args)
	{
		HashMap<String,Integer> hashMap = new HashMap<String,Integer>();
		for (int i = 0; i < 100;i++)
		{
			Integer i_tmp = new Integer(i);
			String s = new Integer(i).toString();
			hashMap.put(s,i_tmp);
			//System.out.println(" hashMap.size:" + hashMap.size() + "\thashMap.capacity:" + hashMap.capacity());
			System.out.println(" hashMap.size:" + hashMap.size());
		}
	}
}
