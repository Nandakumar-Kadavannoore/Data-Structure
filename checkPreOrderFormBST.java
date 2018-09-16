
	private static boolean canRepresentBST(int pre[], int n) {
		Stack<Integer> stack = new Stack<Integer>();
		int root  = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			if (pre[i]<root)
				return false;
			while (!stack.isEmpty() && stack.peek() < pre[i]) {
				root = stack.pop();
			}
			stack.push(pre[i]);
		}
		
		return true;
	}
	
