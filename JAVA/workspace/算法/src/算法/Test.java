package Ëã·¨;

public class Test {
	
	public static void main(String[] args) {
		Counter c1 = new Counter("counter1");
		c1.increment();
		Counter c2 = new Counter("counter2");
		c2.increment();
		System.out.println(c1.getname() + c1.tally());
		System.out.println(c2.getname() + c2.tally());
	}
}
