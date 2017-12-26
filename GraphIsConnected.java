package tree;

import java.util.Iterator;
import java.util.LinkedList;

class Graph {
	int numberOfNodes;
	LinkedList<Integer> adjacenyList[];

	@SuppressWarnings("unchecked")
	Graph(int numberOfNodes) {
		this.numberOfNodes = numberOfNodes;
		adjacenyList = new LinkedList[numberOfNodes];
		for (int count = 0; count < numberOfNodes; count++) {
			adjacenyList[count] = new LinkedList<>();
		}
	}

	// To Add Connection to graph
	public void addConnection(int source, int destination) {
		this.adjacenyList[source].addFirst(destination);
		this.adjacenyList[destination].addFirst(source);
	}

	// To Print Graph
	public void printGraph() {
		for (int count = 0; count < this.numberOfNodes; count++) {
			System.out.println("Adjaceny List for Vertex -> " + count);
			for (Integer element : this.adjacenyList[count]) {
				System.out.print(" " + element);
			}
			System.out.println();
		}
	}

	// To Transpose graph
	public Graph getTranspose() {
		Graph graph = new Graph(this.numberOfNodes);
		for (int count = 0; count < this.numberOfNodes; count++) {
			// Just ReArrange
			Iterator<Integer> iterator = this.adjacenyList[count].listIterator();
			while (iterator.hasNext()) {
				this.adjacenyList[iterator.next()].add(count);
			}
		}
		return graph;
	}

}

class MainClass {

	public static void main(String... args) {
		Graph graph = new Graph(5);
		graph.addConnection(0, 1);
		graph.addConnection(0, 4);
		graph.addConnection(1, 2);
		graph.addConnection(1, 3);
		graph.addConnection(1, 4);
		graph.addConnection(2, 3);
		graph.addConnection(3, 4);

		graph.printGraph();

	}

	// Used to Check is Graph is Connected
	static Boolean isConnected(int numberOfNodes, Graph graph) {
		Boolean[] visited = new Boolean[numberOfNodes];
		clearVisitedData(visited, numberOfNodes);
		// Perform the DFS traversal
		dFSUtil(0, visited, graph);
		// Check if all nodes are visited
		if (!checkIsVisitedAll(visited, numberOfNodes))
			return false;
		// Reverse the graph
		Graph newGraph = graph.getTranspose();
		// Erase the visited array to false
		clearVisitedData(visited, numberOfNodes);
		// Perform DFS traversal
		dFSUtil(0, visited, newGraph);
		// Check if all nodes are visited
		// if true return true
		return checkIsVisitedAll(visited, numberOfNodes) ? true : false;
	}

	// Helper Function for check if all nodes are visited
	static boolean checkIsVisitedAll(Boolean[] visited, int numberOfNodes) {
		for (int count = 0; count < numberOfNodes; count++) {
			if (!visited[count])
				return false;
		}
		return true;
	}

	// Helper Function for clear visited Array
	static Boolean[] clearVisitedData(Boolean[] visited, int numberOfNodes) {
		for (int count = 0; count < numberOfNodes; count++) {
			visited[count] = false;
		}
		return visited;
	}

	// Helper Function for DFS traversal
	static void dFSUtil(int node, Boolean[] visited, Graph graph) {
		visited[node] = true;

		int nextNode;

		Iterator<Integer> iterator = graph.adjacenyList[node].iterator();
		while (iterator.hasNext()) {
			nextNode = iterator.next();
			if (!visited[nextNode])
				dFSUtil(nextNode, visited, graph);

		}
	}

}
