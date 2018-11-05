void findCombinations(String string, int index, String out) {
		if (index  == string.length())
			System.out.println(out);
		for (int i = index; i < string.length(); i++)
			findCombinations(string, index + 1, out + "(" + string.substring(index, i + 1 - index) + ")");
	}
	
