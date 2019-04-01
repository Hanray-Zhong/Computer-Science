package NO_2_BasicProgramming;

import java.util.Scanner;

public class ComputeAreaWithConstant {

	public static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		// Declare a constant
		final double PI = 3.14159;
		
		double radius = input.nextDouble();
		
		double area = radius * radius * PI;
		
		System.out.println("The area for the circle of radius " +radius + " is " + area);
		
	}

}
