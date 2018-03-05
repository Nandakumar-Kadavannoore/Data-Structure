
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

class Node {
	int data;
	Node left, right;

	Node(int item) {
		data = item;
		left = right = null;
	}
}

class MainClass {

	public static void main(String... args) {
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);
		root.right.left.right = new Node(8);
		root.right.right.right = new Node(9);
		System.out.println("Vertical Order traversal is");
		printVerticalOrder(root);

	}

	private static void printVerticalOrder(Node root) {
		TreeMap<Integer, List<Integer>> treeMap = new TreeMap<>();

		getVerticalOrder(root, 0, treeMap);
	}

	private static void getVerticalOrder(Node node, int horizontalDistance, TreeMap<Integer, List<Integer>> treeMap) {

		if (node == null)
			return;

		List<Integer> nodeDataList = treeMap.get(horizontalDistance);

		if (nodeDataList.isEmpty()) {
			nodeDataList = new ArrayList<>();
		}
		nodeDataList.add(node.data);
		treeMap.put(horizontalDistance, nodeDataList);

		getVerticalOrder(node.left, horizontalDistance - 1, treeMap);
		getVerticalOrder(node.right, horizontalDistance + 1, treeMap);
	}

}
