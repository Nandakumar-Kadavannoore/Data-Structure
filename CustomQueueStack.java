
	public class QStack {
		Stack<Integer> stack;
		
	   void push(Stack<Integer> top, int newData) {
			top.push(newData);
		}
	   
	   int pop(Stack<Integer> top) {
		   if (top == null) {
			   System.exit(0);
		   }
		   
		   return top.pop();
	   }
	   
	   void enQueue(Stack<Integer> top, int newData) {
		   push(top, newData);
	   }
	   
	   int deQueue(Stack<Integer> stack) {
		   int x, res = 0;
		   
		   if (stack.isEmpty()) {
			   System.exit(0);
		   } else if (stack.size() == 1) {
			   return pop(stack);
		   } else {
			   x = pop(stack);
			   
			   res = deQueue(stack);
			   
			   push(stack, x);
			   
			   return res;
		   }
		   return 0;
	   }
		
		
		
	}
	
	
	
