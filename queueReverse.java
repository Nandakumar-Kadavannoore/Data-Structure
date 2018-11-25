class Queue_Reverse {

static Queue<Integer> queue; 
  
    // Utility function to print the queue 
    static void Print() 
    { 
        while (!queue.isEmpty()) { 
            System.out.print( queue.peek() + ", "); 
            queue.remove(); 
        } 
    } 
  
    // Function to reverse the queue 
    static void reversequeue() 
    { 
        Stack<Integer> stack = new Stack<>(); 
        while (!queue.isEmpty()) { 
            stack.add(queue.peek()); 
            queue.remove(); 
        } 
        while (!stack.isEmpty()) { 
            queue.add(stack.peek()); 
            stack.pop(); 
        } 
    } 
  

}
