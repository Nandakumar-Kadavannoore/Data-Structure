/**
 * Group of words of same characters
 * 
 * @author Nandakumar.k
 *
 */

public class Main {

	public static void main(String... args) {
	   List<String> stringList = Arrays.asList( "abc", "bca" , "xyx" , "xyz");
	   process(stringList);
	}

	private static int calculateSumValue(String inputString) {
		int totalCount = 0;
		for (int i = 0; i < inputString.length(); i++) {
			char eachCharacter = inputString.charAt(i);
			totalCount += eachCharacter - 'a';
		}
		return totalCount;
	}

	private static void process(List<String> stringList) {
		Map<Integer, List<String>> hashMap = new HashMap<>();
		stringList.parallelStream().forEach(inputString -> {
			int keyValue = calculateSumValue(inputString);
			updateHashMap(hashMap, inputString, keyValue);
		});
		hashMap.forEach((key, value) -> {
			for (int i = 0; i < value.size(); i++) {
				System.out.print(value.get(i) + " ");
			}
			System.out.println();
		});
	}

	private static void updateHashMap(Map<Integer, List<String>> hashMap, String inputString, int keyValue) {
		List<String> stringList;
		if (hashMap.containsKey(keyValue)) {
			stringList = hashMap.get(keyValue);
			stringList.add(inputString);
			hashMap.remove(keyValue);
			hashMap.put(keyValue, stringList);
		} else {
			stringList = new ArrayList<>();
			stringList.add(inputString);
			hashMap.put(keyValue, stringList);
		}

	}

}
