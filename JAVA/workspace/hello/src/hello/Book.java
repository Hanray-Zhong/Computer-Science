package hello;

public class Book {

	private String name = "���μ�";

	public String getname() {
		return name;
	}

	public static void main(String[] args) {
		Book b = new Book();
		System.out.println(b.getname());
		System.out.println(new Book().getname());
		TransferProperty t = new TransferProperty();
		t.Call();
	}
}