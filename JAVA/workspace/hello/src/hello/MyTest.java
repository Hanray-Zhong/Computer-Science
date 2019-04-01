package hello;

public class MyTest {

	private String name = "hanray";

	public void GetName() {
		int id = 0416;
		System.out.println(id + name);
	}

	public static void main(String[] args) {
		MyTest test = new MyTest();
		test.GetName();
	}
}
