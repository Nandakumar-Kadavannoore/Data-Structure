
	class Node {
		int data;
		Node left, right;
		Node (int data) {
			this.data  = data;
			left = right = null;
		}
	}
	
	class BinaryTree {
		Node constructTreeUtil(int post[], int size) {
			Node root = new Node(post[size-1]);
			Stack<Node> stack = new Stack<>();
			stack.push(root);
			
			for (int i = size - 2; i >= 0; --i) {
				Node x = new Node(post[i]);
				Node temp = null;
				while (!stack.isEmpty() && post[i] < stack.peek().data) {
					temp = stack.pop();
				}
				if (temp != null)
					temp.left = x;
				else
					stack.peek().right = x;
				stack.push(x);
			}
			return root;
		}
	}
	
	
