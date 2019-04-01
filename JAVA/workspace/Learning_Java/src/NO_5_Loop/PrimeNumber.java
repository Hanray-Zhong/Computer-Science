package NO_5_Loop;

public class PrimeNumber {

	public static void main(String[] args) {
		final int NUMBER_OF_PRIMES = 50; // Number of primes to display
		final int NUMBER_OF_PRIMES_PER_LINE = 10; // Display 10 per line
		int count = 0;
		int number = 2;
		
		System.out.println("The first SO prime numbers are \n");
		
		// Repeatedly find prime numbers
		while (count < NUMBER_OF_PRIMES) {
			// Assume the number is prime
			boolean isPrime = true; // I s the current number prime?
		
			// Test whether number is prime
			for (int divisor = 2; divisor <= number / 2; divisor++) {
				if (number % divisor == 0) { // If true, number is not prime
					isPrime = false; // Set isPrime to false
					break; // Exit the for loop
				}
			}
			
			if(isPrime){
				count++; // Increase the count
				if(count % NUMBER_OF_PRIMES_PER_LINE == 0){
					// Display the number and advance to the new line
					System.out.println(number);
				}
				else {
					System.out.print(number + " ");
				}
			}
			number++;
		}
	}
}