// Java implementation of the approach 
import java.util.*; 

class GfG { 

	// Table for storing 2^ith parent 
	private static int table[][]; 

	// Variable to store the height of the tree 
	private static int height; 

	// Graph 
	private static ArrayList<ArrayList<Integer> > Graph; 

	// Arrays to mark start and end time for a node 
	private static int timeIn[]; 
	private static int timeOut[]; 

	// Timer 
	private static int time; 

	// Private constructor for initializing 
	// the global variables 
	private GfG(int n) 
	{ 

		// log(n) with base 2 
		height = (int)Math.ceil(Math.log10(n) / Math.log10(2)); 
		table = new int[n + 1][height + 1]; 

		// Fill the graph with empty lists 
		Graph = new ArrayList<ArrayList<Integer> >(); 
		for (int i = 0; i <= n; i++) 
			Graph.add(new ArrayList<Integer>()); 
		timeIn = new int[n + 1]; 
		timeOut = new int[n + 1]; 
		time = 0; 
	} 

	// Filling with -1 as initial 
	private static void preprocessing(int n) 
	{ 
		for (int i = 0; i < n + 1; i++) { 
			Arrays.fill(table[i], -1); 
		} 
	} 

	// Dfs for pre-processing sparse table and 
	// calculating start and end time 
	private static void dfs(int s, int p) 
	{ 
		// Parent at 1 node distance is always 
		// it's direct parent 
		table[s][0] = p; 

		// Start time noted 
		timeIn[s] = ++time; 

		// Filling sparse table recursively 
		for (int i = 1; i <= height; i++) 
			table[s][i] = table[table[s][i - 1]][i - 1]; 

		// Traversing children of source 
		for (int child : Graph.get(s)) { 
			if (child == p) 
				continue; 
			dfs(child, s); 
		} 

		// End time noted 
		timeOut[s] = ++time; 
	} 

	// Helper function to check lowest common Ancestor 
	private static boolean check(int u, int v) 
	{ 
		return timeIn[u] <= timeIn[v] && timeOut[u] >= timeOut[v]; 
	} 

	// Function to return Lowest Common Ancestor of U and V 
	private static int lowestCommonAncestor(int U, int V) 
	{ 
		if (check(U, V)) 
			return U; 

		if (check(V, U)) 
			return V; 

		for (int i = height; i >= 0; i--) { 
			if (!check(table[U][i], V)) 
				U = table[U][i]; 
		} 

		return table[U][0]; 
	} 

	// Function that return true if R 
	// exists on the path between U 
	// and V in the given tree 
	private static boolean isPresent(int U, int V, int R) 
	{ 

		// Dfs 
		dfs(1, 1); 

		// Calculating LCA between U and V 
		int LCA = lowestCommonAncestor(U, V); 

		// Calculating LCA between U and R 
		int LCA_1 = lowestCommonAncestor(U, R); 

		// Calculating LCA between U and V 
		int LCA_2 = lowestCommonAncestor(V, R); 

		if (LCA == R || (LCA_1 == LCA && LCA_2 == R) 
			|| (LCA_2 == LCA && LCA_1 == R)) { 
			return true; 
		} 
		return false; 
	} 

	// Driver code 
	public static void main(String args[]) 
	{ 
		// Number of vertices 
		int n = 6; 
		GfG obj = new GfG(n); 

		// Create the graph 
		preprocessing(n); 
		Graph.get(1).add(2); 
		Graph.get(2).add(1); 
		Graph.get(1).add(3); 
		Graph.get(3).add(1); 
		Graph.get(2).add(4); 
		Graph.get(4).add(2); 
		Graph.get(2).add(5); 
		Graph.get(5).add(2); 
		Graph.get(3).add(6); 
		Graph.get(6).add(3); 

		int U = 4, V = 6, R = 2; 
		if (isPresent(U, V, R)) 
			System.out.print("Yes"); 
		else
			System.out.print("No"); 
	} 
} 
