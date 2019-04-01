package NO_5_Loop;

import java.util.Scanner;

public class GreatestCommonDivisor {
	
	public static Scanner input;

	public static void main(String[] args) {
		input = new Scanner(System.in);
		
		System.out.print("Enter first integer: ");
		int n1 = input.nextInt();
		System.out.print("Enter second integer: ");
		int n2 = input.nextInt();
		
		// Initial gcd is 1
		int gcd = 1;
		int k = 2;
		while (k <= n1 && k <= n2) {
			if (n1 % k == 0 && n2 % k == 0) {
				gcd = k;
			}
			k++;
		}
		
		System.out.println("The greatest common divisor for " + n1 + " and " + n2 + " is " + gcd);

	}

}
