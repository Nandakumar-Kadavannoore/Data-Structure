/*
 To print all interpretations of an integer array
@author Nandakumar.K
*/
import java.util.Arrays;

class Node {
	String dataString;
	Node right;
	Node left;
	
	Node(String dataString) {
		this.dataString = dataString;
	}
	
	public String getDataString() {
		return this.dataString;
	}
}

public class MainClass {
	
	private static final String[] alphabet = {"", "a", "b", "c", "d", "e",
	        "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
	        "s", "t", "u", "v", "w", "x", "v", "z"};

	public static void main(String[] args) {
		    int[] array = {1, 2, 2, 1};
	        printAllInterpretations(array);
	}

	static void printAllInterpretations(int[] array) {
		Node root = createTree(0, "", array);
		printLeaf(root);
		System.out.println();
	}
	
	public static Node createTree(int data, String pString, int[] array) {
		
		if (data > 26)
			return null;
		
		String dataToString = pString + alphabet[data];
		
		Node root = new Node(dataToString);
		
		if (array.length != 0) {
			data = array[0];
			int newArray[] = Arrays.copyOfRange(array, 1, array.length);
			
			root.left = createTree(data, dataToString, newArray);
			
			if (array.length > 1) {
				data = array[0] * 10 + array[1];
				
				newArray = Arrays.copyOfRange(array, 2, array.length);
				
				root.right = createTree(data, dataToString, newArray);
			}
		}
		
		return root;
	}
	
	public static void printLeaf(Node root) {
		if (root == null)
			return;
		
		if (root.left == null && root.right == null)
			System.out.println(root.getDataString() + " ");
		
		printLeaf(root.left);
		printLeaf(root.right);
	}
	
}
