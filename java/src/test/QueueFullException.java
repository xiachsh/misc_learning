package   myPackage;


public class QueueFullException extends Exception
{
	public QueueFullException()
	{
		super("the Queue had reached to the capacity");
	}
}
