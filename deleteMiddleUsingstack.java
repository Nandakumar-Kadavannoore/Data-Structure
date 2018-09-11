// delete middle element
	static void deleteMiddle(Stack<Integer> stack, int size, int currentPosition) {
		if (stack.empty() || currentPosition == size)
			return;
		
		int data = stack.pop();
		deleteMiddle(stack, size, currentPosition++);
		if (size/2 != currentPosition)
			stack.push(data);
	}
	
	
