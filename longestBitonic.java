public class MainClass {
	
	public static void main(String ... args) {
		int arr[] = {1,2,3,4,5,6,7,8};
	    System.out.println("Longest Bitonic is "+bitonic(arr, arr.length));
		
	}
  
  static int bitonic(int arr[], int n) {
		int[] inc = new int[n];
		int[] dec = new int[n];
		
		inc[0] = dec[n-1] = 1;
		
		for (int i = 1; i < n; i++)
			inc[i] = (arr[i] >= arr[i-1]) ? inc[i-1] + 1 : 1;
		
		for (int i = n-2 ; i >= 0 ; i--)
			dec[i] = (arr[i] >= arr[i+1]) ? dec[i+1] + 1 : 1;
		
		int max = inc[0] + dec[0] - 1;
		for (int i = 1; i<n; i++)
			if (inc[i] + dec[i] - 1 > max)
				max = inc[i] + dec[i] - 1;
		return max;
	}
  }
