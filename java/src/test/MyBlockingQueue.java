package myPackage;


import java.util.Queue;

public class MyBlockingQueue<T> 
{
	private static class NodeList<T> 
	{
		T element;
		NodeList<T> next;
		NodeList(T t) 
		{
			element = t;
			this.next = null;
		} 
	}
	private transient NodeList<T> header;
	private transient NodeList<T> tail;
	private int size;
	private int capacity;
	private static Object pushLock = new Object();
	private static Object pullLock = new Object();
	private static final int QUEUE_CAPACTITY = 128;
	private static final int DEFAULT_TIMEVAL = 50; /* sleep 50 millis second to wait the queue to be ready */



	public MyBlockingQueue()
	{
		header = tail = null;
		size = 0;
		capacity = QUEUE_CAPACTITY;
	}
	public MyBlockingQueue(java.util.Queue<T> queue) throws InterruptedException,QueueFullException
	{
		capacity = QUEUE_CAPACTITY;
		if (queue != null)
		{
			header = tail = null;
			int cnt = 0;
			for (T ele: queue)
			{
				
				if (cnt > QUEUE_CAPACTITY)
				throw new QueueFullException();
				
				addTail(ele);	
				cnt++ ;
			}
		}	
	}
	public void addTail(T element) throws InterruptedException 
	{
		if (header == null)
		{
			tail = header = new NodeList<T> (element);
			size++;
		}
		else	
		{
			while(size == capacity)
				Thread.sleep(DEFAULT_TIMEVAL);
			NodeList<T> tmp = header;
			while(tmp.next != null)
				tmp = tmp.next;
	 		tmp.next = new NodeList<T> (element);
			size++;
		}
	}
	public void push(T element) throws InterruptedException 
	{		
		synchronized(this.pushLock)
		{
			
			if (element != null)
			{
				addTail(element);
			}
		}
	}	
	public T pull() throws InterruptedException 
	{
		synchronized(this.pullLock)
		{
			while (size<=0)
				Thread.sleep(DEFAULT_TIMEVAL);	
			NodeList<T> tmp = header;
			header = header.next;
			size--;
			return tmp.element;
		}
	}

}
