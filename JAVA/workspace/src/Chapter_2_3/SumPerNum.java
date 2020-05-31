package Chapter_2_3;
import java.util.Scanner;
public class SumPerNum {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Enter a number between 0 and 1000 : ");
		int number = scanner.nextInt();
		int result = 0;

		while(number >= 10) {
			result += number % 10;
			number /= 10;
		}

		result += number;

		System.out.println("The sum of the digits is " + result);
	}

}
