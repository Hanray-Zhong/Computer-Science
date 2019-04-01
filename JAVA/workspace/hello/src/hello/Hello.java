package hello;

import java.util.Scanner;

public class Hello {

	public static int Sum(int a, int b) {
		int sum = 0;
		for (int i = a; i <= b; i++) {
			sum += i;
		}
		return sum;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println(Sum(10, 20));
		
	}

}
