/*
Find the Kth Smallest Element Sum
@author Nandakumar K
*/
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
    System.out.printIn("The Kth Smallest Element Sum is "+ kThSmallestElementsSum(root,2,0));

	}
  
   private static int kThSmallestElementsSum(Node node, int limit, int count) {
		 if (node == null)
			 return 0;
		 if (count > limit)
			 return 0;
		 int result = kThSmallestElementsSum(node.left, limit, count);
		 if (count >= limit)
			 return result;
		 result += node.data;
		 count++;
		 if (count >= limit)
			  return result;
		 return result + kThSmallestElementsSum(node.right, limit, count);
	 }
  
  }
