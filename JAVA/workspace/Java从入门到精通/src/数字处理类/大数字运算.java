package ���ִ�����;

import java.math.BigInteger;

public class ���������� {
	public static void main(String[] args) {
		BigInteger bigInstance = new BigInteger("4");
		System.out.println("��2���㣺" + bigInstance.add(new BigInteger("2")));
		System.out.println("��2���㣺" + bigInstance.subtract(new BigInteger("2")));
		System.out.println("��2���㣺" + bigInstance.multiply(new BigInteger("2")));
		System.out.println("��2���㣺" + bigInstance.divide(new BigInteger("2")));
		System.out.println("2�η����㣺" + bigInstance.pow(2));
		System.out.println("ȡ�෴�����㣺" + bigInstance.negate());
		
	}

}
