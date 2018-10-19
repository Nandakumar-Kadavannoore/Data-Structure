static Queue<Integer> queue = new LinkedList<Integer>();
	
	static boolean checkSorted(int n) {
		Stack<Integer> stack = new Stack<>();
		
		int expected = 1;
		int front;
		
		while (queue.size() != 0) {
			front =  queue.peek();
			queue.poll();
			
			if (front == expected)
				expected++;
			else {
				if (stack.size() == 0) {
					stack.push(front);
				} else if (stack.size() != 0 && stack.peek() < front) {
					return false;
				} else {
					stack.push(front);
				}
			}
			
			while (stack.size() != 0 && stack.peek() == expected) {
				stack.pop();
				expected++;
			}
		}
		
		if (expected - 1 == n &&  stack.size() == 0)
			return true;
		
		return false;
	}
	
