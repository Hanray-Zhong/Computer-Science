package 数字处理类;

import java.math.BigInteger;

public class 大数字运算 {
	public static void main(String[] args) {
		BigInteger bigInstance = new BigInteger("4");
		System.out.println("加2运算：" + bigInstance.add(new BigInteger("2")));
		System.out.println("减2运算：" + bigInstance.subtract(new BigInteger("2")));
		System.out.println("乘2运算：" + bigInstance.multiply(new BigInteger("2")));
		System.out.println("除2运算：" + bigInstance.divide(new BigInteger("2")));
		System.out.println("2次方运算：" + bigInstance.pow(2));
		System.out.println("取相反数运算：" + bigInstance.negate());
		
	}

}
