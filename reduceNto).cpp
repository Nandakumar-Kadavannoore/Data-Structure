// Java implementation for the above approach

import java.io.*;
import java.util.*;

class Minimumize {

	static class Node {

		int val, moves;

		// Constructor
		public Node(int val, int moves)
		{

			this.val = val;
			this.moves = moves;
		}
	}

	// Function to calculate
	// minimum number of moves
	// required to convert N to 0
	public static int minMoves(int N)
	{

		// Initialize a hashset
		// to mark the visited numbers
		Set<Integer> set = new HashSet<>();

		// Initialize a queue
		Queue<Node> q = new LinkedList<>();

		// Mark 0 as visited
		set.add(0);

		// Add 0 into the queue
		q.add(new Node(0, 0));

		// while N is not reached
		while (!q.isEmpty()) {

			// poll out current node
			Node curr = q.poll();

			// If N is reached
			if (curr.val == N) {

				// Return the number of moves used
				return curr.moves;
			}

			if (!set.contains(curr.val - 1)) {

				// Mark the number as visited
				set.add(curr.val - 1);

				// Add the number in the queue
				q.add(new Node(curr.val - 1,
							curr.moves + 1));
			}
			if (!set.contains(curr.val + 1)) {

				// Mark the number as visited
				set.add(curr.val + 1);

				// Add the number in the queue
				q.add(new Node(curr.val + 1,
							curr.moves + 1));
			}
			if (!set.contains(curr.val * 2)) {

				// Mark the number as visited
				set.add(curr.val * 2);

				// Add the number in the queue
				q.add(new Node(curr.val * 2,
							curr.moves + 1));
			}
			int sqr = curr.val * curr.val;
			if (!set.contains(sqr)) {

				// Mark the number as visited
				set.add(sqr);

				// Add the number in the queue
				q.add(new Node(sqr,
							curr.moves + 1));
			}
			if (!set.contains(-curr.val)) {

				// Mark the number as visited
				set.add(-curr.val);

				// Add the number in the queue
				q.add(new Node(-curr.val,
							curr.moves + 1));
			}
		}

		return -1;
	}

	// Driver code
	public static void main(String[] args)
	{

		int N = 50;

		// Call the function
		// and print the answer
		System.out.println(minMoves(N));
	}
}
