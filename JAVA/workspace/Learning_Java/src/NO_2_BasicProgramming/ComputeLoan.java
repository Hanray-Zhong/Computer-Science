package NO_2_BasicProgramming;

import java.util.Scanner;

public class ComputeLoan {

	private static Scanner input;

	public static void main(String[] args) {
		input = new Scanner(System.in);
		// Enter annual interest rate in percentage, e.g., 7.25%
		System.out.print("Enter annual interest rate, e.g.y 7.25%: ");
		double annualInterestRate = input.nextDouble();
		// Obtain monthly interest rate
		double monthlylnterestRate = annualInterestRate / 1200;
		// Enter number of years
		System.out.print("Enter number of years as an integer, e.g., 5: ");
		int numberOfYears = input.nextInt();
		
		// Enter loan amount
		System.out.print("Enter loan amount, e.g., 120000.95: ");
		double loanAmount = input.nextDouble();
		
		// Calculate payment
		double monthlyPayment = loanAmount * monthlylnterestRate / 
				(1 - 1 / Math.pow(1 + monthlylnterestRate, numberOfYears * 12));
		double totalPayment = monthlyPayment * numberOfYears * 12;
		
		// Display results
		System.out.println("The monthly payment is S" +(int)(monthlyPayment * 100)/ 100.0);
		System.out.println("The total payment is S" +(int)(totalPayment * 100)/ 100.0);
	}

}
