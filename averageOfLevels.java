  static void averageOfLevels(Node root) {
            Queue<Node> queue = new LinkedList<>();
            queue.add(root);
            int sum = 0, count = 0;

            while (!queue.isEmpty()) {
                sum = 0;
                count = 0;
                Queue<Node> temp = new LinkedList<>();
                while (!queue.isEmpty()) {
                    Node node = queue.peek();
                    sum += node.data;
                    count++;

                    if (node.left != null)
                        temp.add(node.left);

                    if (node.right != null)
                        temp.add(node.right);
                }

                queue = temp;
                System.out.print(( sum * 1.0 / count) + " " );
            }
        }
