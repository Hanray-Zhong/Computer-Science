package NO_11_�̳кͶ�̬;

import java.util.ArrayList;

public class TestArrayList {

	public static void main(String[] args) {
		// Create a list to store cities
		ArrayList<String> cityList = new ArrayList<String>();
		
		// Add some cities in the list
		cityList.add ("London");		// cityList now contains [London]
		cityList.add ("Denver") ;		// cityList now contains [London , Denver]
		cityList.add("Paris");			// cityList now contains [London, Denver, Paris]
		
		System.out.println("List size? " + cityList.size());
		System.out.println("Is Miami in the list? " + cityList.contains("Miami"));
		System.out.println("The location of Denver in the list? " + cityList.indexOf("Denver"));
		System.out.println("Is the list empty? " + cityList.isEmpty()) ; // Print false
		// insert a new city in index 2
		cityList.add(2, "Xian");
		// Contains [London, Denver, Xian, Paris]
		
		// Remove a city at index 1
		cityList.remove(1);
		// Contains [London, Xian, Paris]
		
		// Display the contents in the list
		System.out.println(cityList.toString());
		
		// Display the contents in the list in reverse order
		for (int i = cityList.size() - 1; i >= 0; i--)
			System.out.print(cityList.get(i) + " ");
		System.out.println();
		
		// Create a list to store two class objects
		// ArrayList<Class> list = new ArrayList();
		
		// Add two circles
		// list,add(new Class(parameter_1..));
		// list.add(new Class(parameter_2..));
		
		
	}

}
