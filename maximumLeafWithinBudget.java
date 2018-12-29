// Java program to calculate the maximum number of leaf 
// nodes that can be visited within the given budget 
import java.io.*; 
import java.util.*; 
import java.lang.*; 

// Class that represents a node of the tree 
class Node { 
	int data; 
	Node left, right; 

	// Constructor to create a new tree node 
	Node(int key) 
	{ 
		data = key; 
		left = right = null; 
	} 
} 

class GFG { 

	// Priority queue to store the levels 
	// of all the leaf nodes 
	static PriorityQueue<Integer> pq; 

	// Level order traversal of the binary tree 
	static void levelOrder(Node root) 
	{ 
		Queue<Node> q = new LinkedList<>(); 
		int len, level = 0; 
		Node temp; 

		// If tree is empty 
		if (root == null) 
			return; 

		q.add(root); 

		while (true) { 

			len = q.size(); 
			if (len == 0) 
				break; 
			level++; 
			while (len > 0) { 

				temp = q.remove(); 

				// If left child exists 
				if (temp.left != null) 
					q.add(temp.left); 

				// If right child exists 
				if (temp.right != null) 
					q.add(temp.right); 

				// If node is a leaf node 
				if (temp.left == null && temp.right == null) 
					pq.add(level); 
				len--; 
			} 
		} 
	} 

	// Function to calculate the maximum number of leaf nodes 
	// that can be visited within the given budget 
	static int countLeafNodes(Node root, int budget) 
	{ 
		pq = new PriorityQueue<>(); 
		levelOrder(root); 
		int val; 

		// Variable to store the count of 
		// number of leaf nodes possible to visit 
		// within the given budget 
		int count = 0; 

		while (pq.size() != 0) { 

			// Removing element from 
			// min priority queue one by one 
			val = pq.poll(); 

			// If current val is under budget, the 
			// node can be visited 
			// Update the budget afterwards 
			if (val <= budget) { 
				count++; 
				budget -= val; 
			} 
			else
				break; 
		} 
		return count; 
	} 

	// Driver code 
	public static void main(String args[]) 
	{ 

		Node root = new Node(10); 
		root.left = new Node(8); 
		root.right = new Node(15); 
		root.left.left = new Node(3); 
		root.left.left.right = new Node(13); 
		root.right.left = new Node(11); 
		root.right.right = new Node(18); 

		int budget = 8; 

		System.out.println(countLeafNodes(root, budget)); 
	} 
} 
