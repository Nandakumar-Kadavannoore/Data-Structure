static void deleteMiddle(Stack<Character> stack, int n, int current) {
		
		if (stack.isEmpty() || current == n)
			return ;
		char x = stack.pop();
		deleteMiddle(stack, n, current + 1);
		if (current != n/2)
			stack.push(x);
		
		
	}
