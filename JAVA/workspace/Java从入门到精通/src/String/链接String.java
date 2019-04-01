package String;

public class 链接String {

	public static void main(String[] args) {
		String s1 = new String("Hello");
		String s2 = new String("word");
		String s = s1 + " " + s2;
		System.out.println(s);
		
		int size1 = s.indexOf('o');
		int size2 = s.lastIndexOf('o');
		int size3 = s.indexOf('k');
		
		System.out.println(size1 + " " + size2 + " " + size3);//返回的是脚标

	}

}
