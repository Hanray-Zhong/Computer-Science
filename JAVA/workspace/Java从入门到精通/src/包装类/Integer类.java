package ��װ��;

public class Integer�� {
	public static void main(String[] args) {
		String str[] = {"89", "10", "33", "19", "35", "27"};
		int sum = 0;
		for(int i = 0; i < str.length; i++)
		{
			int myint = Integer.parseInt(str[i]);
			sum += myint;
		}
		System.out.println("String�����е�����֮��Ϊ��" + sum);
		
		/*------------------------------------------*/
		String str0 = Integer.toString(456);
		String str1 = Integer.toBinaryString(456);
		String str2 = Integer.toOctalString(456);
		String str3 = Integer.toHexString(456);
		
		System.out.println("ʮ���ƣ�" + str0);
		System.out.println("�����ƣ�" + str1);
		System.out.println("�˽��ƣ�" + str2);
		System.out.println("ʮ�����ƣ�" + str3);
		/*------------------------------------------*/
		
		System.out.println("int ����Сֵ�����ֵ��" + Integer.MIN_VALUE + " " + Integer.MAX_VALUE);
		System.out.println("int �����Ƶ�λ����" + Integer.SIZE);
	}
}
