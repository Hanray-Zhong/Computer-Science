package NO_5_Loop;

import java.util.Scanner ;

public class Dec2Hex {
	
	public static Scanner input;

	public static void main(String[] args) {
		input = new Scanner(System.in);
		
		System.out.print("Enter a decimal number: ");
		int decimal = input.nextInt();
		
		// Convert decimal
		String hex  = "";
		
		while (decimal != 0) {
			int hexValue = decimal % 16;
			
			char hexDigit = (hexValue <= 9 && hexValue >= 0) ? (char)(hexValue + '0') : (char)(hexValue - 10 + 'A');
			
			hex = hexDigit + hex;
			decimal = decimal / 16;
		}

		System.out.println("The hex number is " + hex);
	}

}
