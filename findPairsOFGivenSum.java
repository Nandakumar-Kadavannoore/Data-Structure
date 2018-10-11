
	class Pair {
		int first, second;
		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
	
	
	boolean findPairs(int array[]) {
		HashMap<Integer, Pair> map = new HashMap<>();
		int size = array.length;
		
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				int sum = array[i] +  array[j];
				if (!map.containsKey(sum))
					map.put(sum, new Pair(i, j));
				else {
					return true;
				}
			}
		}
		
		return false;
	}
	
