/*
Implementation of Find the three Triplet
@author Nandakumar.k
*/

 public class Main { 	
	public static void main(String ... args) {
		int arr[] = {1,2,3,4,5,6,7,8};
		findThreeTriplet(arr);
		
	}
  
  static void findThreeTriplet(int arr[]) {
		int length = arr.length;
		int max = length - 1;
		int min = 0;
		
		int[] smaller = new int[length];
		smaller[0] = -1;
		for (int i = 1; i < length ; i++) {
			if (arr[i] <= arr[min]) {
				min = i;
				smaller[i] = -1;
			} else
				smaller[i] = min;
		}
		
		int[] greater = new int[length];
		greater[length - 1] = -1;
		for (int i = length-2 ; i >= 0 ; i--) {
			if (arr[i] >= arr[max]) {
				max = i;
				greater[i] = -1;
			} else
				greater[i] = max;
		}
		
		
		for (int i = 0; i < length; i++) {
			if (smaller[i] != -1 && greater[i] != -1) {
				System.out.println(arr[smaller[i]]+ " "
						+ arr[i] + " "
						+ arr[greater[i]]);
			}
		}
	}
  }
