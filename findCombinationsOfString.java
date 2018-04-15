/**
 * Find Combination of String
 * @author Nandakumar.k
 *
 */

public class Main {

	public static void main(String... args) {
		String string = "xyz";
		findCombinations(string, 0, "");
	}

	static void findCombinations(String input, int index, String out) {
		if (index == input.length()) {
			System.out.println(out);
		}
		for (int i = index; i < input.length(); i++)
			findCombinations(input, i + 1, out + "(" + input.substring(index, i + 1) + ")");
	}
  }
