

class SpecialStack extends Stack<Integer> {
	
	Stack<Integer> minimum = new Stack();
	
	void push(int data) {
		if (isEmpty() == true) {
			super.push(data);
			minimum.push(data);
		} else {
			super.push(data);
			int poppedData = minimum.pop();
			if (data < poppedData)
				minimum.push(data);
			else
				minimum.push(data);
		}
	}
	
	public Integer pop() {
		int data = super.pop();
		minimum.pop();
		return data;
	}
	
	int getMin() {
		int data = minimum.pop();
		minimum.push(data);
		return data;
	}
	
}
