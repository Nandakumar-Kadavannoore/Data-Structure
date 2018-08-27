
	static int kthLargestSum(int array[], int n, int k) {
		int sum[] = new int[n+1];
		sum[0] = 0;
		sum[1] = array[0];
		for (int i = 2; i <= n; i++)
			sum[i] = sum[i-1] + array[i-1];
		
		PriorityQueue<Integer> queue = new PriorityQueue<>();
		
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				int x = sum[j] - sum[i-1];
				if (queue.size() < k)
					queue.add(x);
				else {
					   if (queue.peek() < x) {
						   queue.poll();
						   queue.add(x);
					   }
				}
			}
		}
		return queue.poll();
	}
	
