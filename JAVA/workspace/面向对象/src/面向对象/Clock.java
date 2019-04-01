package 面向对象;

import display.Display;

public class Clock 
{

	private Display hours = new Display(24);
	private Display seconds = new Display(60);

	public void Start() 
	{
		for (;;) 
		{
			seconds.increase();
			if (seconds.GetValue() == 0)
				hours.increase();
			System.out.printf("%d:%d\n", hours.GetValue(), seconds.GetValue());
		}
	}

	public static void main(String[] args) 
	{
		Clock clock = new Clock();
		clock.Start();
	}

}
