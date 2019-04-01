package NO_12_“Ï≥£¥¶¿Ì;

import java.util.Scanner;

public class QuotientWithException {

	public static Scanner input = new Scanner(System.in);
	
	public static int Quotient(int number1, int number2) {
		if (number2 == 0) {
			throw new ArithmeticException("Divisior cannot be zero");
		}
		
		return number1 / number2;
	}
	
	public static void main(String[] args) {
		System.out.print("Enter two integers: ");
		int number1 = input.nextInt();
		int number2 = input.nextInt();
		
		try {
			int result = Quotient(number1, number2);
			System.out.println(number1 + "/" + number2 + " is " + result);
		}
		catch (ArithmeticException ex) {
			System.out.println("Exception: an integer cannot be divided by zero");
		}
		
		System.out.println("Execution continues...");
		
	}

}
