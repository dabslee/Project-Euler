package projecteuler37;

public class PE37 {
	static boolean isPrime(int n) {
		if (n < 2) return false;
		if (n < 4) return true;
		for (int i = 2; i < (int)Math.pow(n, 0.5)+1; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
	
	static int truncateleft(int n) {
		if (n > 9) return Integer.parseInt(Integer.toString(n).substring(1));
		return 0;
	}
	
	static int truncateright(int n) {
		return n/10;
	}
	
	static boolean checkleft(int n) {
		while (n != 0) {
			if (!isPrime(n)) {
				return false;
			}
			n = truncateleft(n);
		}
		return true;
	}
	
	static boolean checkright(int n) {
		while (n != 0) {
			if (!isPrime(n)) {
				return false;
			}
			n = truncateright(n);
		}
		return true;
	}
	
	public static void main(String args[]) {
		int count = 0;
		int mysum = 0;
		int i = 9;
		while (count < 11) {
			i++;
			if (checkleft(i) && checkright(i)) {
				count++;
				mysum += i;
			}
		}
		System.out.println(mysum);
	}
}
