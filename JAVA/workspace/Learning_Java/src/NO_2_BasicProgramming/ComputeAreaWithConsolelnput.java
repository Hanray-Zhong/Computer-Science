package NO_2_BasicProgramming;

import java.util.Scanner;

public class ComputeAreaWithConsolelnput {

	private static Scanner input;

	public static void main(String[] args) {
		input = new Scanner(System.in);
		
		// Prompt the user to enter a radius
		System.out.print ("Enter a number for radius: ");
		double radius = input .nextDouble();
		
		// Compute area
		double area = radius * radius * 3.14159;
		
		// Display results
		System.out .println("The area for the circle of radius " +
		radius + " is " + area);

	}

}
