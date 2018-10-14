static void sortStack(Stack<Integer> stack) {
		if (!stack.isEmpty()) {
			int x = stack.pop();
			sortStack(stack);
			sortedInsert(stack, x);
		}
	}
	
	static void sortedInsert(Stack<Integer> stack, int x) {
		if (stack.isEmpty() || x > stack.peek()) {
			stack.push(x);
			return;
		}
		
		int temp  = stack.pop();
		sortedInsert(stack, x);
		stack.push(temp);
	}
	
