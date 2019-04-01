package 数字处理类;

import java.util.Random;

public class 随机数random {
	
	
	//
	public static int GetNumber(double num1, double num2) {
		//产生num1 -- num2 之间的随机数
		int s = (int) num1 + (int) (Math.random() * (num2 - num1));//random() 默认返回 0-1
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
		System.out.println("2 - 32 的随机数：" + GetNumber(2, 32));
		System.out.println("a - z 的随机字符：" + GetRandomChar('a', 'z'));
		/*****************************************************/
		Random r = new Random();
		System.out.println("随机生成一个整数：" + r.nextInt());
	}
}
