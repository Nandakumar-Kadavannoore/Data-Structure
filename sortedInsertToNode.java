class Node {
		int data;
		Node next;
		Node(int data) {
			this.data = data;
			this.next = null;
		}
    void sortedInsert(Node node) {
		Node current;
		
		if (head == null || head.data >= node.data) {
			node.next = head;
			head = node;
		} else {
			current = head;
			while (current.next != null && 
					current.next.data < node.data)
				current = current.next;
			node.next = current.next;
			current.next = node;
		}
	}
    }
    
    
    public class Main {

	public static void main(String... args) {
	   /*
     Write code to insert
     */
	}

	

	
}
