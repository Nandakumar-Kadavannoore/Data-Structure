// Java Program for above approach
import java.util.*;

// Structure of a Node
class Node {
	int data;
	Node left;
	Node right;

	Node(int data)
	{
		this.data = data;
		left = right = null;
	}
}

// Inorder Iterator class
class InorderIterator {
	private Stack<Node> traversal;

	InorderIterator(Node root)
	{
		traversal = new Stack<Node>();
		moveLeft(root);
	}

	private void moveLeft(Node current)
	{
		while (current != null) {
			traversal.push(current);
			current = current.left;
		}
	}

	public boolean hasNext()
	{
		return !traversal.isEmpty();
	}

	public Node next()
	{
		if (!hasNext())
			throw new NoSuchElementException();

		Node current = traversal.pop();

		if (current.right != null)
			moveLeft(current.right);

		return current;
	}
}

// Class to Test given set of inputs
class Test {

	// Driver Code
	public static void main(String args[])
	{
		Node root = new Node(8);
		root.right = new Node(9);
		root.left = new Node(3);
		root.left.left = new Node(2);
		root.left.right = new Node(4);
		root.left.right.right = new Node(5);

		InorderIterator itr = new InorderIterator(root);
		try {
			System.out.print(itr.next().data + " ");
			System.out.print(itr.hasNext() + " ");
			System.out.print(itr.next().data + " ");
			System.out.print(itr.next().data + " ");
			System.out.print(itr.next().data + " ");
			System.out.print(itr.hasNext() + " ");
			System.out.print(itr.next().data + " ");
			System.out.print(itr.next().data + " ");
			System.out.print(itr.hasNext() + " ");
		}
		catch (NoSuchElementException e) {
			System.out.print("No such element Exists");
		}
	}
}
