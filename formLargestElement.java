
   private static long solve(int [] array) {
	   PriorityQueue<Integer> pQueue = new PriorityQueue<>();
	   StringBuilder numberOne = new StringBuilder();
	   StringBuilder numberTwo = new StringBuilder();
	   
	   for (int number: array) {
		   pQueue.add(number);
	   }
	   
	   while (!pQueue.isEmpty()) {
		   numberOne.append(pQueue.poll() + "");
		   if (pQueue.isEmpty())
			    numberTwo.append(pQueue.poll() + "");
	   }
	   
	   return Long.parseLong(numberOne.toString()) +
			   Long.parseLong(numberTwo.toString());
   }
