/*
Graph implemented as Adjacency linked List
@author Nandakumar K
*/

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
			System.out.println("Adjaceny List for Vertex -> "+count);
			for (Integer element : this.adjacenyList[count]) {
				System.out.print(" " + element);
			}
			System.out.println();
		}
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

}
