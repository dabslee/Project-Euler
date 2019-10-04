
public class PE7 {

	public static boolean isprime(int n) {
		if (n < 2) {
			return false;
		}
		boolean is = true;
		for (int i = 2; i <= (int)Math.pow(n, 0.5); i++) {
			if (n % i == 0) is = false;
		}
		return is;
	}
	
	public static void main(String args[]) {
		int count = 0;
		int i = 1;
		while (count < 10001) { // third prime
			i++;
			if (isprime(i)) count++;
		}
		System.out.println(i);
	}
	
}
