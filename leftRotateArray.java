/*
Left Rotate Array
@author Nandakumar.K
*/

public class Main {
	
	public static void main(String ... args) {
		int arr[] = {1,2,3,4,5,6,7,8};
		leftRotate(arr, 3);
		printArray(arr);
		
	}
	
	static void leftRotate(int arr[], int distance) {
		int length = arr.length;
		reverseArray(arr, 0, distance - 1);
		reverseArray(arr, distance, length - 1);
		reverseArray(arr, 0, length -1);
	}
	
	static void reverseArray(int arr[], int start, int end) {
		int temp;
		while (start < end) {
			temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			start++;
			end--;
		}
	}
	
	static void printArray(int arr[]) {
		for (int i = 0; i < arr.length ; i++)
			System.out.println(arr[i] + " ");
	}
  }
