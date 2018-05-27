/**
Find the loop in linked list 
@author Nandakumar.k
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
	
	public boolean detectLoop() {
		Node slow = head;
		Node fast = head;
		while (slow != null && fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
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
	   if (linkedList.detectLoop()) {
		System.out.println("Found Loop");   
	   }
	}

	
}
