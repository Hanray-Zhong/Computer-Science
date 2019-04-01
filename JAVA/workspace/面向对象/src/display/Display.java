package display;

public class Display {
	
	private int value = 0;
	private int limit = 0;
	
	public Display(int limit)
	{
		this.limit = limit;
	}
	
	public void increase()
	{
		value++;
		if(value == limit)
			value = 0;	
	}
	
	public int GetValue()
	{
		return value;
	}
	
//	public static void main(String[] args) {
//		Display hours = new Display(24);
//		for(;;)
//		{
//			hours.increase();
//			System.out.println(hours.GetValue());
//		}

//	}

}
