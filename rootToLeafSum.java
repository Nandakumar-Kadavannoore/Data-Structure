/*
 Find Sum from root to leaf
 @author Nandakumar K
*/

class Node {
	int data;
	Node left,right;
	
	Node(int item) {
		data = item;
		left = right = null;
	}

	boolean hasPathSum(Node node, int sum) {
		if (node == null)
			 return (sum == 0);
		else {
			int subSum = sum - node.data;
			if (subSum ==  0 && node.left == null
					&& node.right == null)
				return true;
			return  hasPathSum(node.left, subSum)
					|| hasPathSum(node.right, subSum);
		   }	
		}


}
