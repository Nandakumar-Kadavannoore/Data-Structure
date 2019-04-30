// Java implementation of the approach 
import java.util.*; 
public class GFG { 

	// A binary tree node 
	public static class Node { 
		int data; 
		Node left, right, root; 

		Node(int data) 
		{ 
			this.data = data; 
		} 
	} 

	// Function to add a node to the BST 
	public static Node AddNode(Node root, int data) 
	{ 

		// If the tree is empty, return a new node 
		if (root == null) { 
			root = new Node(data); 
			return root; 
		} 

		// Otherwise, recur down the tree 
		if (root.data < data) 
			root.right = AddNode(root.right, data); 

		else if (root.data > data) 
			root.left = AddNode(root.left, data); 

		return root; 
	} 

	// Function to find the target pairs 
	public static void TargetPair(Node node, int tar) 
	{ 

		// LeftList which stores the left side values 
		ArrayList<Node> LeftList = new ArrayList<>(); 

		// RightList which stores the right side values 
		ArrayList<Node> RightList = new ArrayList<>(); 

		// curr_left pointer is used for left side execution and 
		// curr_right pointer is used for right side execution 
		Node curr_left = node; 
		Node curr_right = node; 

		while (curr_left != null || curr_right != null
			|| LeftList.size() > 0 && RightList.size() > 0) { 

			// Storing the left side values into LeftList 
			// till leaf node not found 
			while (curr_left != null) { 
				LeftList.add(curr_left); 
				curr_left = curr_left.left; 
			} 

			// Storing the right side values into RightList 
			// till leaf node not found 
			while (curr_right != null) { 
				RightList.add(curr_right); 
				curr_right = curr_right.right; 
			} 

			// Last node of LeftList 
			Node LeftNode = LeftList.get(LeftList.size() - 1); 

			// Last node of RightList 
			Node RightNode = RightList.get(RightList.size() - 1); 

			int leftVal = LeftNode.data; 
			int rightVal = RightNode.data; 

			// To prevent repetition like 2, 6 and 6, 2 
			if (leftVal >= rightVal) 
				break; 

			// Delete the last value of LeftList and make 
			// the execution to the right side 
			if (leftVal + rightVal < tar) { 
				LeftList.remove(LeftList.size() - 1); 
				curr_left = LeftNode.right; 
			} 

			// Delete the last value of RightList and make 
			// the execution to the left side 
			else if (leftVal + rightVal > tar) { 
				RightList.remove(RightList.size() - 1); 
				curr_right = RightNode.left; 
			} 

			// (left value + right value) = target 
			// then print the left value and right value 
			// Delete the last value of left and right list 
			// and make the left execution to right side 
			// and right side execution to left side 
			else { 
				System.out.println(LeftNode.data + " " + RightNode.data); 

				RightList.remove(RightList.size() - 1); 
				LeftList.remove(LeftList.size() - 1); 
				curr_left = LeftNode.right; 
				curr_right = RightNode.left; 
			} 
		} 
	} 

	// Driver code 
	public static void main(String[] b) 
	{ 

		Node root = null; 
		root = AddNode(root, 2); 
		root = AddNode(root, 6); 
		root = AddNode(root, 5); 
		root = AddNode(root, 3); 
		root = AddNode(root, 4); 
		root = AddNode(root, 1); 
		root = AddNode(root, 7); 
		int sum = 8; 
		TargetPair(root, sum); 
	} 
} 
