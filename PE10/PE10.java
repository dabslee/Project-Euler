
public class PE10 {
	public static boolean isprime(int n) {
		if (n > 1 && n < 4) return true;
		for (int f = 2; f <= (int)Math.sqrt(n); f++) {
			if (n % f == 0) return false;
		}
		return true;
	}
	
	public static void main(String args[]) {
		long mysum = 2;
		int upto = 2000000;
		for (int i = 3; i < upto; i += 2) {
			if (isprime(i)) {
				mysum += i;
			}
		}
		System.out.println(mysum);
	}
}
