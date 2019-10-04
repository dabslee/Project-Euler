public class PE31 {
	public static void main(String args[]) {
		int poss[] = {1, 2, 5, 10, 20, 50, 100, 200};
		int dynamic[] = new int[201];
		dynamic[0] = 1;
		for (int i = 0; i < poss.length; i++) {
			for (int j = poss[i]; j < 201; j++) {
				dynamic[j] += dynamic[j - poss[i]];
			}
		}
		
		System.out.println(dynamic[200]);
	}
}
