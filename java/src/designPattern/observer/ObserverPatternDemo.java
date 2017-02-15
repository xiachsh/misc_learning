package xiachsh.learning.designPattern.observer;



public class ObserverPatternDemo
{
	public static void main(String [] args)
	{
		Subject subject = new Subject();
		
		new OctalObserver(subject);
		new BinaryObserver(subject);
	
		System.out.println("First State changed to:15");
		subject.setState(15);
		System.out.println("First State changed to:19");
		subject.setState(19);
	}
}

