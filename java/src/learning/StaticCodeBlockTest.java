package learning;
import learning.StaticCodeBlock;
public class StaticCodeBlockTest
{

	static 
	{
		System.out.println("Load " + StaticCodeBlockTest.class.getName());

	}


	public static void main (String [] args)
	{

		StaticCodeBlock x = new StaticCodeBlock();
		StaticCodeBlock y = new StaticCodeBlock();
	}
}
