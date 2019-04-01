package NO_2_BasicProgramming;

import java.util.Scanner;

public class ComputeAverage {

	private static Scanner input;
	
	public static void main(String[] args) {
		input = new Scanner(System.in);
		// Prompt the user to enter three numbers
		System.out.print("Enter three numbers: ") ;
		double numberl = input.nextDouble();
		double number2 = input.nextDouble();
		double number3 = input.nextDouble();
		
		// Compute average
		double average = (numberl + number2 + number3) / 3;
		
		// Display results
		System.out.println ("The average of " + numberl + " " + number2
		+ " " + number3 + " is " + average) ;

	}

}
