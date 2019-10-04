
public class PE3 {
	public static boolean isPrime(int n) {
		if (n < 2) return false;
		if (n < 4) return true;
		for (int f = 2; f <= (int)Math.pow(n, 0.5); f++) {
			if (n % f == 0) return false;
		}
		return true;
	}
	public static void main(String args[]) {
		long n = 600851475143L;
		int maxi = 0;
		int i = 2;
		while (i <= n) {
			if (n % i == 0 && isPrime(i)) {
				maxi = i;
				n /= i;
			}
			i++;
		}
		System.out.println(maxi);
	}
}
