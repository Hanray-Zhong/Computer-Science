package Chapter_4_5;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CountCharacter {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String input = null;
		Map<Character, Integer> characterMap = new HashMap<Character, Integer>();

		System.out.println("Input: ");
		input = scanner.nextLine();

		for (int i = 0; i < input.length(); i++){
			Character currentCharacter = input.charAt(i);
			if (!Character.isLetter(currentCharacter))
				continue;
			if (Character.isUpperCase(currentCharacter))
				currentCharacter = Character.toLowerCase(currentCharacter);
			if (!characterMap.containsKey(currentCharacter)) {
				characterMap.put(currentCharacter, 1);
			}
			else {
				characterMap.put(currentCharacter, characterMap.get(currentCharacter) + 1);
			}
		}

		System.out.println(characterMap);

	}

}
