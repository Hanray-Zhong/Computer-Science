package NO_12_�쳣����;

import java.util.Scanner;

public class Quotient {
	
	public static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		System.out.print("Enter two integers: ");
		int number1 = input.nextInt();
		int number2 = input.nextInt();
		
		if (number2 != 0)
			System.out.println(number1 + " / " + number2 + " is " + (number1 / number2));
		// �쳣����
		else 
			System.out.println("Divisior cannot be zero");
	}

}
