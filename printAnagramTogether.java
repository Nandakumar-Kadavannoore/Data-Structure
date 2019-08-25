// An efficient program to print all 
// anagrams together	 
import java.util.Arrays; 
import java.util.LinkedList; 

public class GFG 
{ 
	static final int NO_OF_CHARS = 26; 
	
	// Class to represent a Trie Node 
	static class TrieNode 
	{ 
		boolean isEnd; // indicates end of word 
		
		// 26 slots each for 'a' to 'z' 
		TrieNode[] child = new TrieNode[NO_OF_CHARS]; 
		
		// head of the index list 
		LinkedList<Integer> head; 
		
		// constructor 
		public TrieNode() 
		{ 
			isEnd = false; 
			head = new LinkedList<>(); 
			for (int i = 0; i < NO_OF_CHARS; ++i) 
				child[i] = null; 
		} 
	} 
	
	// A utility function to insert a word to Trie 
	static TrieNode insert(TrieNode root,String word, 
								int index, int i) 
	{ 
		// Base case 
		if (root == null) 
		{ 
			root = new TrieNode(); 
		} 
		
		if (i < word.length() ) 
		{ 
			int index1 = word.charAt(i) - 'a'; 
			root.child[index1] = insert(root.child[index1], 
									word, index, i+1 ); 
		} 
		else // If end of the word reached 
		{ 
			// Insert index of this word to end of 
			// index linked list 
			if (root.isEnd == true) 
			{ 
				root.head.add(index); 
			} 
			else // If Index list is empty 
			{ 
				root.isEnd = true; 
				root.head.add(index); 
			} 
		} 
		return root; 
	} 

	// This function traverses the built trie. When a leaf 
	// node is reached, all words connected at that leaf 
	// node are anagrams. So it traverses the list at leaf 
	// node and uses stored index to print original words 
	static void printAnagramsUtil(TrieNode root, 
									String wordArr[]) 
	{ 
		if (root == null) 
			return; 
	
		// If a lead node is reached, print all anagrams 
		// using the indexes stored in index linked list 
		if (root.isEnd) 
		{ 
			// traverse the list 
			for(Integer pCrawl: root.head) 
				System.out.println(wordArr[pCrawl]); 
		} 
	
		for (int i = 0; i < NO_OF_CHARS; ++i) 
			printAnagramsUtil(root.child[i], wordArr); 
	} 
	
	// The main function that prints all anagrams together. 
	// wordArr[] is input sequence of words. 
	static void printAnagramsTogether(String wordArr[], 
											int size) 
	{ 
		// Create an empty Trie 
		TrieNode root = null; 
	
		// Iterate through all input words 
		for (int i = 0; i < size; ++i) 
		{ 
			// Create a buffer for this word and copy the 
			// word to buffer 
			char[] buffer = wordArr[i].toCharArray(); 
			
			// Sort the buffer 
			Arrays.sort(buffer); 
	
			// Insert the sorted buffer and its original 
			// index to Trie 
			root = insert(root, new String(buffer), i, 0); 
			
		} 
		
		// Traverse the built Trie and print all anagrms 
		// together 
		printAnagramsUtil(root, wordArr); 
	} 
	
	// Driver program to test above functions 
	public static void main(String args[]) 
	{ 
		String wordArr[] = {"cat", "dog", "tac", "god", 
										"act", "gdo"}; 
		int size = wordArr.length; 
		printAnagramsTogether(wordArr, size); 
	} 
} 

