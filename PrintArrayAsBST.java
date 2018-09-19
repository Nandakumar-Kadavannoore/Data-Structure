	private static void printSorted(int[] array, int start, int end) {
		if (start > end)
			return;
		printSorted(array, start * 2 + 1, end);
		System.out.println(array[start] + " ");
		printSorted(array, start * 2 + 2, end);
	}
