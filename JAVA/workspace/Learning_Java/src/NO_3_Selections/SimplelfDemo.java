package NO_3_Selections;

import java.util.Scanner;

public class SimplelfDemo {

	private static Scanner input;

	public static void main(String[] args) {
		input = new Scanner(System.in);
		System.out.println("Enter an integet: ");
		int number = input.nextInt();
		
		if (number % 5 == 0) {
			System.out.println("HiFive") ;
		}
		
		if (number % 2 == 0) {
			System.out.println("HiEven") ;
		}
			
		else {
			System.out.println("else!!");
		}
	}
}

