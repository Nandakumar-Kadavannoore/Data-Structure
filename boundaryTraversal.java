
public class MainClass {
	
	class Node {
		int data;
		Node left, right;
		
		Node (int data) {
			this.data = data;
			left = right = null;
		}
	}
	
	class BinaryTree {
		Node root;
		
		void printLeaves(Node node) {
			if (node != null) {
				printLeaves(node.left);
				if (node.left == null && node.right == null)
					System.out.println(node.data + " ");
				printLeaves(node.right);
			}
		}
		
		void printBoundaryLeft(Node node) {
			if ( node != null) {
				if (node.left != null)  {
					System.out.println(node.data + " ");
					printBoundaryLeft(node.left);
				} else if (node.right != null) {
					System.out.println(node.data + " ");
					printBoundaryLeft(node.right);
				}
			}
		}
		
		void printBoundaryRight(Node node) {
			if ( node != null) {
				if (node.right != null) {
					printBoundaryRight(node.right);
					System.out.println(node.data + " ");
				} else if (node.left != null) {
					printBoundaryRight(node.left);
					System.out.println(node.data + " ");
				}
			}
		}
		
		void printBoundary(Node node) {
			if (node != null) {
				System.out.println(node.data + " ");
				printBoundaryLeft(node.left);
				
				printLeaves(node.left);
				printLeaves(node.right);
				
				printBoundaryRight(node.right);
			}
		}
		
		
	}
  }
