static long solve(int[] array) {
		PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
		
		StringBuilder numberOne = new StringBuilder();
		StringBuilder numberTwo = new StringBuilder();
		
		for (int x : array)
			priorityQueue.add(x);
		
		while (!priorityQueue.isEmpty()) {
			numberOne.append(priorityQueue.poll() + "");
			if (!priorityQueue.isEmpty()) 
				numberTwo.append(priorityQueue.poll() + "");
		}
		
		long sum = Long.parseLong(numberOne.toString()) +
				   Long.parseLong(numberTwo.toString());
		
		return sum;
	}
