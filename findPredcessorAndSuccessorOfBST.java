private static void findPreAndSec(Node node, Node pre, Node suc, int key) {
		if (node == null)
			return;

		if (node.data == key) {
			if (node.left != null) {
				Node temp = node.left;
				while (temp.right != null) {
					temp = temp.right;
				}
				pre = temp;
			}
			if (node.right != null) {
				Node temp = node.right;
				while (temp.left != null) {
					temp = temp.left;
				}
				suc = temp;
			}
			return;
		}

		if (node.data > key) {
			suc = node;
			findPreAndSec(node.left, pre, suc, key);
		} else {
			pre = node;
			findPreAndSec(node.right, pre, suc, key);
		}
	}
