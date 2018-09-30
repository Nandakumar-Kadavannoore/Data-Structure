	
	boolean hasOnlyOneChild(int pre[], int size) {
		int nextDiff, lastDiff;
		
		for (int i = 0; i < size - 1; i++) {
			nextDiff = pre[i] - pre[i+1];
			lastDiff = pre[i] - pre[size - 1];
			if (nextDiff * lastDiff < 0)
				return false;
		}
		
		return true;
	}
	
