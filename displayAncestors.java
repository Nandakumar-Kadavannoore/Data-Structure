
class Node {
	int data;
	Node left;
	Node right;

	Node(int item) {
		data = item;
		left = right = null;
	}
}

class MainClass {

	public static void main(String... args) {
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);
		root.right.left.right = new Node(8);
		root.right.right.right = new Node(9);
    System.out.println("The Ancestors of node 7 are " + printAncestors(root, 7));
	}
	
	
	boolean printAncestors(Node node, int target) {
		if (node == null)
			return false;
		if (node.data == target)
			return true;
		if (printAncestors(node.left, target) || 
				printAncestors(node.right, target)) {
			System.out.println(node.data + " ");
		}
	   return false;		
    }
  }  
