import java.util.*; 
import java.lang.*; 
import java.io.*; 

public class MainClass { 

	// Function to return the count of lucky number 
	static int countLuckyNum(int n) 
	{ 

		int count = 0, i = 1; 
		while (true) { 
			if (n >= ((1 << i) - 1)) 
				count++; 
			else
				break; 
			i++; 
		} 
		return count; 
	} 

	// Driver code 
	public static void main(String[] args) 
	{ 
		int n = 7; 
		System.out.println(countLuckyNum(n)); 
	} 
} 
