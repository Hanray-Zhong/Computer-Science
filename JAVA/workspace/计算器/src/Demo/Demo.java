package Demo;

import java.util.Scanner;

import javax.swing.text.PlainDocument;

public class Demo {

	// 定义一个能够让用户输入的Scanner变量
	public static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		
		String str;
		float a1;
		float a2;
		char ch;

		System.out.println("Input any key or input \"esc\" to exit:");
		str = sc.nextLine();

		while(!str.equals("esc")){
			System.out.println("Input the first number:");
			a1 = sc.nextFloat();
			sc.nextLine();
			System.out.println("Input the character:");
			ch = sc.nextLine().charAt(0);
			System.out.println("Input the second number:");
			a2 = sc.nextFloat();
			sc.nextLine();

			switch(ch){
				case '+': System.out.println("The rasult is: " + (a1 + a2));
							break;
				case '-': System.out.println("The rasult is: " + (a1 - a2));
							break;
				case '*': System.out.println("The rasult is: " + (a1 * a2));
							break;
				case '/': System.out.println("The rasult is: " + (a1 / a2));
							break;
				case '%': System.out.println("The rasult is: " + (a1 % a2));
							break;
				default:  System.out.println("Input invalid!!!");
			}

			System.out.println("\n------------------------------------------------------");
			System.out.println("Input any key or input \"esc\" to exit:");
			str = sc.nextLine();
		}
		

	}

}
