package �㷨;

import java.util.Scanner;

public class ���Լ��_____ŷ������㷨 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a, b;
		a = in.nextInt();
		b = in.nextInt();
		System.out.println("���Լ��Ϊ��" + gcd(a, b));
	}

	static int gcd(int p, int q)
	{
		if(q == 0) return p;
		int r = p % q;
		return gcd(q, r);
	}
}
