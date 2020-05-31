package Chapter_4_5;

import java.util.ArrayList;
import java.util.List;

public class GenerateCarNumber {

	public static void main(String[] args) {
		List<StringBuffer> result = new ArrayList<StringBuffer>();
		StringBuffer carNumber = null;

		while (result.size() < 5) {
			int loopTime = 0;

			carNumber = Generate();
			for (int i = 0; i <= result.size(); i++) {
				if (result.contains(carNumber)) {
					break;
				}
				if (i == result.size()) {
					result.add(carNumber);
				}
			}

			if (++loopTime >= 100) {
				System.out.println("Time out");
				break;
			}
		}
		System.out.println(result);

	}
	public static StringBuffer Generate() {
		StringBuffer carNumber = new StringBuffer();
		char c1 = (char)(int)(Math.random() * 26 + 65);
		char c2 = (char)(int)(Math.random() * 26 + 65);
		char c3 = (char)(int)(Math.random() * 26 + 65);
		int x1 = (int)(Math.random() * 10);
		int x2 = (int)(Math.random() * 10);
		int x3 = (int)(Math.random() * 10);
		int x4 = (int)(Math.random() * 10);
		carNumber.append(c1);
		carNumber.append(c2);
		carNumber.append(c3);
		carNumber.append(x1);
		carNumber.append(x2);
		carNumber.append(x3);
		carNumber.append(x4);

		return carNumber;
	}

}
