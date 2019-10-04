package projecteuler41;

public class PE41 {
	static boolean checkpan(int n) {
		String nstr = Integer.toString(n);
		int ndigits = nstr.length();
		for (int i = 1; i < ndigits + 1; i++) {
			if (!nstr.contains(Integer.toString(i))) {
				return false;
			}
		}
		return true;
	}
	
	static boolean checkprime(int n) {
		if (n < 2) return false;
		if (n < 4) return true;
		for (int i = 2; i < (int)Math.pow(n, 0.5)+1; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
	
	public static void main(String args[]) {
		int mymax = 0;
		for (int i = 1; i < 100000000; i++) {
			if (checkpan(i) && checkprime(i)) {
				mymax = i;
			}
		}
		System.out.println(mymax);
	}
}
