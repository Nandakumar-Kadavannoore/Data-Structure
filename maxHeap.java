/**
Implementation of Max Heap 
@author Nandakumar.K
**/

import javax.management.RuntimeErrorException;

public class Heap {
	
  private int[] heapArray;
	
	private int maxSize;
	
	private int heapSize;
	
	public Heap(int max) {
		maxSize = max;
		heapSize = 0;
		heapArray = new int[maxSize];
	}
	
	public boolean isEmpty() {
		return heapSize == 0;
	}
	
	public boolean insert(int element) {
		
		if (heapSize + 1 == maxSize)
			return false;
		heapArray[++heapSize] = element;
		int position = heapSize;
		
		while (position != 1 && element > heapArray[position/2]) {
			heapArray[position] = heapArray[position/2];
			position /= 2;
		}
		
		heapArray[position] = element;
		return true;
	}
	
	public int remove() {
		int parent,child;
		int item, temp;
		if (isEmpty()) {
			throw new RuntimeException("Error: Heap Empty");
		}
		
		item = heapArray[1];
		temp = heapArray[heapSize - 1];
		
		parent = 1;
		child = 2;
		while (child <= heapSize) {
			if ( child < heapSize && heapArray[child] < heapArray[child + 1]) {
				child++;
			}
			if (temp >= heapArray[child])
				break;
			
			heapArray[parent] = heapArray[child];
			parent = child;
			child *= 2;
		}
		heapArray[parent] = temp;
		return item;
	}
	
	public void display() {
		for (int i = 1; i <= heapSize; i++)
			System.out.println(" "+heapArray[i]);
	}
	
	public static void main(String[] args) {
		
	}

}
