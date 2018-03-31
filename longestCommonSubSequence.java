/**
 * find the longest common subsequence 
 * @author Nandakumar.K
 *
 */
public class Main {

	public static void main(String... args) {
		char[] first = "test".toCharArray();
		char[] second = "subtest".toCharArray();
		System.out.println("The longest Common SubSequence is "
				+ longestCommonSubSequence(first, second, first.length, second.length));
	}

	public static int longestCommonSubSequence(char[] first, char[] second, int firstLength, int secondLength) {

		int longest[][] = new int[firstLength + 1][secondLength + 1];

		for (int i = 0; i < firstLength; i++) {
			for (int j = 0; j < secondLength; j++) {
				if (i == 0 || j == 0)
					longest[i][j] = 0;
				else if (first[i - 1] == second[j - 1])
					longest[i][j] = longest[i - 1][j - 1] + 1;
				else
					longest[i][j] = Math.max(longest[i - 1][j], longest[i][j - 1]);
			}
		}
		return longest[firstLength][secondLength];
	}

}
