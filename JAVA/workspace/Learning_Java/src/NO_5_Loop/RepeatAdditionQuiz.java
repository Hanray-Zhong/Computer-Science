package NO_5_Loop;

import java.util.Scanner;

public class RepeatAdditionQuiz {
	
	public static Scanner input;

	public static void main(String[] args) {
		int numberl = (int)(Math.random() * 10);
		int number2 = (int)(Math.random() * 10);
		
		input = new Scanner(System.in);
		
		System.out.print("What is " + numberl + " + " + number2 + " ?");int answer = input.nextInt();
		
		while (numberl + number2 != answer){
			System.out.print("Wrong answer. Try again. What is "+ numberl + " + " + number2 + "?");
			answer = input.nextInt();
		}
		
		System.out.println("You got it!");

	}

}
