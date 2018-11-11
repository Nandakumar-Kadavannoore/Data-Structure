
	int numOfBoxes(int array[], int size, int limit) {
		Arrays.sort(array);
		int i = 0, j = size - 1;
		int answer = 0;
		while ( i <= j) {
			answer++;
			if (array[i] + array[j] <= limit) {
				i++;
			}
			j--;
		}
		return answer;
	}
	
