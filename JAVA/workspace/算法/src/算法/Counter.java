package �㷨;

public class Counter {
	private String name;
	private int t = 0;//��¼����
	
	public Counter(String name)
	{
		this.name = name;
	}
	
	public String getname()
	{
		return this.name;
	}
	
	public void increment()
	{
		t++;
	}
	
	public int tally()
	{
		return t;
	}
}
