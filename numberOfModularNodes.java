class LinkedList {
	Node head;
	class Node {
		int data;
		Node next;
		Node(int data) {
			this.data = data;
			this.next = null;
		}
	}
	
	public void push(int data) {
		Node node = new Node(data);
		node.next = head;
		head = node;
	}
	
  Node modularNode(Node head,int k) {
		if (k <= 0 || head == null)
			return null;
		int count = 1;
		Node modularNode = null;
		for (Node temp = head; temp != null ; temp = temp.next) {
			if (count % k == 0)
				modularNode = temp;
			count++;
		}
	return modularNode;
	}
	
}



public class Main {

	public static void main(String... args) {
	   LinkedList linkedList = new LinkedList();
	   linkedList.push(20);
	   linkedList.push(4);
	   linkedList.push(15);
	   linkedList.push(10);
	   linkedList.head.next.next.next.next = linkedList.head;
		System.out.println("Number of Modular Nodes are " + linkedList.modularNode(linkedList.head,4));   
	  
	}

	
}
