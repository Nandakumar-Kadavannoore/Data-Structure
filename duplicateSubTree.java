class MainClass {

static HashMap<String, Integer> hashMap;
	
	static class Node {
		int data;
		Node left, right;
		Node (int data) {
			this.data = data;
			left = right = null;
		}
	}
	
	static String inOrder(Node node) {
		if (node == null)
			return "";
		String string = "(";
		string += inOrder(node.left);
		string += Integer.toString(node.data);
		string += inOrder(node.right);
		string += ")";
		
		if (hashMap.get(string) != null && hashMap.get(string) == 1)
			System.out.println(node.data);
		
		if (hashMap.containsKey(string))
			hashMap.put(string, hashMap.get(string) + 1);
		else
			hashMap.put(string, 1);
		
		return string;
	}
	}
