package Chapter_6_7;

import java.util.Arrays;
import java.util.Scanner;

import javax.rmi.CORBA.Util;

public class SortRows {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter a 3-by-3 matrix row by row:");
		double[][] inputArray = new double[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				inputArray[i][j] = scanner.nextDouble();
			}
		}
		SortRows(inputArray);
		System.out.println("The row-sorted array is");
		PrintArray(inputArray);
	}
	public static void SortRows(double[][] array) {
		for (int i = 0; i < array.length; i++) {
			Arrays.sort(array[i]);
		}
	}
	public static void PrintArray(double[][] a) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
	}
}
