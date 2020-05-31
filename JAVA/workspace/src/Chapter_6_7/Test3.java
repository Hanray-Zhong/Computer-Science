package Chapter_6_7;

import java.util.Scanner;

public class Test3 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Input: ");
		int row = scanner.nextInt();
		int[][] result = CreateArray(row);
		PrintArray(result);
	}

	public static int[][] CreateArray(int row) {
		if (row <= 0) {
			System.out.println("Row cannot be 0 or lower than 0");
			return null;
		}

		int[][] result = new int[row][];
		for (int i = row; i > 0; i--) {
			int[] tempArray = new int[i];
			result[row - i] = tempArray;
		}

		return result;
	}

	public static void PrintArray(int[][] a) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
	}

}
