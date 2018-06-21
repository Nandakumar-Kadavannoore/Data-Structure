/*
To Print Largest Number that can be formed
@author Nandakumar.K
*/
public class MainClass {
	
	public static void main(String ... args) {
		Vector<String> vectors = new Vector<>();
		vectors.add("2345");
		vectors.add("6556");
		printLargest(vectors);
		
	}
	
	//make largest
	static void printLargest(Vector<String> arr)
	{
		Collections.sort(arr,new Comparator<String>(){
			@Override
			public int compare(String X, String Y) {
				String XY =  X + Y;
				String YX = Y + X;
				return XY.compareTo(YX) > 0 ? -1 : 1;
			}
		});
		
		Iterator it = arr.iterator();
		while (it.hasNext()) {
			System.out.println(it.next());
		}
	}
	
  }
