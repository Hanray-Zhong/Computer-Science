package NO_3_Selections;

import java.util.Scanner;

public class SubtractionQuiz {

	private static Scanner input;

	public static void main(String[] args) {
		// 1.Generate two random single-digit integers
		int numberl = (int)(Math.random() * 10);
		int number2 = (int)(Math.random() * 10);
		
		// 2. If numberl < number2, swap numberl with number2
		if (numberl < number2){
			int temp = numberl;
			numberl = number2;
			number2 = temp;
		}
		
		// B. Prompt the student to answer "What is numberl - numb¡¸e 2?¡±
		System.out.print("What is " + numberl + " - " + number2 + "?");
		input = new Scanner(System.in);
		int answer = input.nextInt();
		
		// 4. Grade the answer and display the result
		if (numberl - number2 == answer)
			System.out.println("You are correct!");
		else {
			System.out.println("Your answer is wrong.");
			System.out.println(numberl + " - " + number2 + " should be " + (numberl - number2));
		}

	}

}
