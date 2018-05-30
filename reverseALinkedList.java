/**
  Reverse a linked list
  @Nandakumar.K
**/

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
 }

public class Main {

	public static void main(String... args) {
	   LinkedList linkedList = new LinkedList();
	   linkedList.push(20);
	   linkedList.push(4);
	   linkedList.push(15);
	   linkedList.push(10);
	   linkedList.head.next.next.next.next = linkedList.head;
	   linkedList.head = reverse(linkedList.head);
	}

	private static Node reverse(Node node) {
		Node prev = null;
		Node current = node;
		Node next = null;
		while (current != null) {
			next = current.next;
			current.next = prev;
			prev = current;
			current = next;
		}
		node = prev;
		return node;
	}

	
}
