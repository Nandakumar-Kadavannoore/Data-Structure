static Boolean subArrayexist(int array[]) {
		
		HashMap<Integer, Integer> map = new HashMap<>();
		int sum = 0;
		for (int i = 0; i < array.length; i++) {
			sum += array[i];
			
			if (array[i] == 0 || sum == 0 || map.get(sum) != null)
				return true;
			
			map.put(sum, i);
		}
		return false;
	}
