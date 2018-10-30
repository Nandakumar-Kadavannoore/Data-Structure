	static void printbracketNumber(String expression, int size) {
		int leftBNumber = 1;
		Stack<Integer> rightBNumber = new Stack<>();
		
		for (int i = 0; i < size; i++) {
			if (expression.charAt(i) == '(') {
				System.out.println(leftBNumber);
				rightBNumber.push(leftBNumber);
				leftBNumber++;
			} else if (expression.charAt(i) == ')') {
				System.out.println(rightBNumber.pop());
			}
		}
	}
