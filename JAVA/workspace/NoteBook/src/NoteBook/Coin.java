package NoteBook;

import java.util.HashMap;
import java.util.Scanner;

public class Coin {
	
	private HashMap<Integer, String> coinnames = new HashMap<Integer, String>();
	
	public Coin()
	{
		coinnames.put(1, "penny");
		coinnames.put(10, "dime");
		coinnames.put(25, "quarter");
		coinnames.put(50, "half-doller");
	}
	
	public String GetName(int amount)
	{
		if(coinnames.get(amount) != null)
			return coinnames.get(amount);
		else
			return "Not Found!";
	}
	
	
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int amount = in.nextInt();
		Coin coin = new Coin();
		System.out.println(coin.GetName(amount));
		
	}

}
