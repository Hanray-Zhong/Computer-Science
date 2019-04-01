package NO_6_Methods;

import java.util.Scanner;

public class GreatestCommonDivisorMethod {

	public static Scanner input;
	
	/**main method*/
	public static void main(String[] args) {
		input = new Scanner(System.in);
		
		// Prompt the user to enter two integers
		System.out.print("Enter first integer: ");
		int nl = input.nextInt();
		System.out.print("Enter second integer: ");
		int n2 = input.nextInt();
		
		System.out.println("The greatest common divisor for " + nl + " and " + n2 + " is " + gcd(nl, n2));
	}
	
	/** Return the gcd of two integers */
	public static int gcd(int nl, int n2){
		int gcd = 1; // Initial gcd is 1
		int k = 2; // Possible gcd
	
		while(k <= nl && k <= n2){
			if(nl % k == 0 && n2 % k == 0)
				gcd = k; // Update gcd
			k++;
		}
	
		return gcd; // Return gcd
	}
}
