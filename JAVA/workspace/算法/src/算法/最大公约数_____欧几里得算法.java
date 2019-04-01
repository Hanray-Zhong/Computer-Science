package 算法;

import java.util.Scanner;

public class 最大公约数_____欧几里得算法 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a, b;
		a = in.nextInt();
		b = in.nextInt();
		System.out.println("最大公约数为：" + gcd(a, b));
	}

	static int gcd(int p, int q)
	{
		if(q == 0) return p;
		int r = p % q;
		return gcd(q, r);
	}
}
