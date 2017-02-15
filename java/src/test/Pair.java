public class Pair<T>
{
	public Pair() { first = null; second = null; }
	public Pair(T first, T second) { this.first = first; this.second = second; }
	public T getFirst() { return first; }
	public T getSecond() { return second; }
	public void setFirst(T newValue) { first = newValue; }
	public void setSecond(T newValue) { second = newValue; }
	private T first;
	private T second;
	
	public static void main(String[] args){
		Pair<Integer> integerPair = new Pair(0, 1);
		Pair<String> stringPair = new Pair("thinking in java", "java core");
	}
}
