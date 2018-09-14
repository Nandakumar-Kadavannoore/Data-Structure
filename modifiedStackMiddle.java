
	class DLLNode {
	  DLLNode prev;
	  int data;
	  DLLNode next;
	  DLLNode(int data) {
		  this.data = data;
	  }
	}
	
	class StackModified {
		DLLNode head;
		DLLNode  mid;
		int count;
	}
	
	StackModified createStack() {
		StackModified stack = new StackModified();
		stack.count = 0;
		return stack;
	}
	
	void push(StackModified stack, int data) {
		DLLNode node = new DLLNode(data);
		node.prev = null;
		node.next = stack.head;
		stack.count++;
		if (stack.count == 1)
			stack.mid = node;
		else {
			stack.head.prev = node;
			if (stack.count % 2 != 0)
				stack.mid = stack.mid.prev;
		}
	   stack.head = node;
	}
	
	int pop(StackModified stack) {
		if (stack.count == 0) 
			return -1;
		DLLNode head = stack.head;
		int data = head.data;
		stack.head = head.next;
		
		if (stack.head != null)
			stack.head.prev = null;
		
		if (stack.count % 2 == 0)
			stack.mid = stack.mid.next;
		
		return data;
	}
	
	int findMiddle(StackModified stack) {
		if (stack.count == 0)
			return -1;
		return stack.mid.data;
	}

	
