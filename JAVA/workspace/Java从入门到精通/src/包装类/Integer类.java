package 包装类;

public class Integer类 {
	public static void main(String[] args) {
		String str[] = {"89", "10", "33", "19", "35", "27"};
		int sum = 0;
		for(int i = 0; i < str.length; i++)
		{
			int myint = Integer.parseInt(str[i]);
			sum += myint;
		}
		System.out.println("String数组中的数字之和为：" + sum);
		
		/*------------------------------------------*/
		String str0 = Integer.toString(456);
		String str1 = Integer.toBinaryString(456);
		String str2 = Integer.toOctalString(456);
		String str3 = Integer.toHexString(456);
		
		System.out.println("十进制：" + str0);
		System.out.println("二进制：" + str1);
		System.out.println("八进制：" + str2);
		System.out.println("十六进制：" + str3);
		/*------------------------------------------*/
		
		System.out.println("int 的最小值和最大值：" + Integer.MIN_VALUE + " " + Integer.MAX_VALUE);
		System.out.println("int 二进制的位数：" + Integer.SIZE);
	}
}
