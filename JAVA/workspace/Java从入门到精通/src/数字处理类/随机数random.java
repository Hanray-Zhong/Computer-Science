package ���ִ�����;

import java.util.Random;

public class �����random {
	
	
	//
	public static int GetNumber(double num1, double num2) {
		//����num1 -- num2 ֮��������
		int s = (int) num1 + (int) (Math.random() * (num2 - num1));//random() Ĭ�Ϸ��� 0-1
		if(s % 2 == 0) {
			return s;
		}
		else {
			return s + 1;
		}
	}
	
	//
	public static char GetRandomChar(char char1, char char2) {
		return (char)(char1 + Math.random()*(char2 - char1 + 1));
	}
	
	public static void main(String[] args) {
		System.out.println("2 - 32 ���������" + GetNumber(2, 32));
		System.out.println("a - z ������ַ���" + GetRandomChar('a', 'z'));
		/*****************************************************/
		Random r = new Random();
		System.out.println("�������һ��������" + r.nextInt());
	}
}
