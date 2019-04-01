package 输入输出;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class 标准输入输出 {

	public static void main(String[] args) {
		byte[] buffer = new byte[10];
		for(int i = 0; i <= 9; i++)
		{
			buffer[i] = (byte) i;
		}
		try {
			PrintWriter out = new PrintWriter(
					new BufferedWriter(
						new OutputStreamWriter(
								new FileOutputStream("a.txt"))));
			int i = 123456;
			out.println(i);
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
