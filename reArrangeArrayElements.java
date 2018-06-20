/*
Find the ReArranged Array Elements
@author Nandakumar.K
*/
public class MainClass {
	
	public static void main(String ... args) {
		int arr[] = {1,2,3,4,5,6,7,8};
		arr = reArrange(arr);
        System.out.println("ReArranged array elements "+arr);
		
	}
	
	// ReArrange Array Elements
	static int[] reArrange(int[] array) {
		Set<Integer> set = new HashSet<Integer>();
		for (int i = 0 ; i < array.length; i++) {
			set.add(array[i]);
		}
		for (int i = 0 ; i < array.length; i++) {
			if (set.contains(i))
				array[i] = i;
			else
				array[i] = -1;
		}
	  return array;
	}
  }
	
