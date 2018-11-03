static int maxDepth(String string) {
		int currentMax = 0;
		int max = 0;
		int length = string.length();
		
		for (int i = 0; i < length; i++) {
			if (string.charAt(i) == '(') {
				currentMax++;
				if (currentMax > max)
					max = currentMax;
			} else if (string.charAt(i) == ')') {
				  if (currentMax > 0)
					  currentMax--;
				  else
					  return -1;
			}
		}
		
		if (currentMax != 0)
			return -1;
		
		return max;
	}
	
	
