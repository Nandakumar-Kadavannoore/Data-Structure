// Java program for the above approach
import java.io.*;
import java.lang.*;
import java.util.*;

class MainClass{

// Function to find the minimum cost
// to convert all distinct characters
// to either uppercase or lowercase
static void minimumCost(String str, int L, int U)
{
	
	// Store the size of the string
	int N = str.length();
	char s[] = str.toCharArray();

	String ans = "";

	// Stores the frequency of lowercase
	// & uppercase characters respectively
	int lowerFreq[] = new int[26];
	int upperFreq[] = new int[26];

	// Traverse the string S
	for(int i = 0; i < N; i++)
	{
		
		// Update uppercase
		// frequency of s[i]
		if (Character.isUpperCase(s[i]))
			upperFreq[s[i] - 'A']++;

		// Otherwise, update lowercase
		// frequency of s[i]
		else
			lowerFreq[s[i] - 'a']++;
	}

	// Stores if the i-th character
	// should be lowercase or not
	int result[] = new int[26];

	// Iterate over the range [0, 25]
	for(int i = 0; i < 26; i++)
	{
		
		// If the character is present
		// in the string
		if (lowerFreq[i] != 0 || upperFreq[i] != 0)
		{
			
			// Store the cost to convert
			// every occurence of i to
			// uppercase and lowercase
			int costToUpper = U * lowerFreq[i];
			int costToLower = L * upperFreq[i];

			// Update result[i] to 1 if
			// lowercase cost is less
			if (costToLower < costToUpper)
			{
				result[i] = 1;
			}
		}
	}

	// Traverse the string S
	for(int i = 0; i < N; i++)
	{
		
		// Store the index
		// of the character
		int index = 0;

		if (Character.isLowerCase(s[i]))
			index = s[i] - 'a';
		else
			index = s[i] - 'A';

		// Convert the current character
		// to uppercase or lowercase
		// according to the condition
		if (result[index] == 1)
		{
			
			// Update s[i]
			s[i] = Character.toLowerCase(s[i]);
		}
		else
		{
			
			// Update s[i]
			s[i] = Character.toUpperCase(s[i]);
		}
	}

	// Print the modified string
	System.out.println(new String(s));
}

// Driver Code
public static void main(String[] args)
{
	String S = "aabbAA";
	int L = 1, U = 1;
	minimumCost(S, L, U);
}
}


