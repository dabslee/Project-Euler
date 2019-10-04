package projecteuler38;

public class PE38 {
	static boolean checkpan(String nstr) {
		if (nstr.length() != 9) return false;
		for (int i = 1; i < 10; i++) {
			if (!nstr.contains(Integer.toString(i))) return false;
		}
		return true;
	}
	
	public static void main(String args[]) {
		int mymax = 0;
		for (int i = 0; i < 10000; i++) {
			for (int n = 1; n < 10; n++) {
				String concated = "";
				for (int j = 1; j < n+1; j++) {
					concated += Integer.toString(i*j);
				}
				if (checkpan(concated)) {
					mymax = Math.max(Integer.parseInt(concated), mymax);
				}
			}
		}
		
		System.out.println(mymax);
	}
}
