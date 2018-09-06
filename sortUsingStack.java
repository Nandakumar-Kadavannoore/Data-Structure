// Sort stack using temparray stack
	static Stack<Integer> sortStack(Stack<Integer> stack) {
		Stack<Integer> tempStack = new Stack<> ();
		while (!stack.isEmpty()) {
			int temp = stack.pop();
			while (!tempStack.isEmpty() && tempStack.peek() > temp) {
				stack.push(tempStack.pop());
			}
			tempStack.push(temp);
		}
		return tempStack;
	}
	
