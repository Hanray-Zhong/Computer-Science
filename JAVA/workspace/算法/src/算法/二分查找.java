package 算法;
import java.util.Arrays;
import java.util.Scanner;

public class 二分查找 {
	
	public static int rank(int key, int[] i)
	{
		int lo = 0;
		int hi = i.length - 1;
		while(lo <= hi)
		{
			int mid = lo + (hi - lo)/2;
			if (key < i[mid]) hi = mid - 1;
			else if (key > i[mid]) lo = mid + 1;
			else return mid;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		int[] whitelist = {4, 5, 10, 14, 1, 24, 50, 12, 26, 11};
		Arrays.sort(whitelist);
		int key;
		Scanner in = new Scanner(System.in);
		key = in.nextInt();
		if(rank(key, whitelist) < 0)
			System.out.println("未找到" + key);
		else 
			System.out.println("找到了");
	}

}
