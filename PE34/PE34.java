package projecteuler34;

public class PE34 {
	static int factorial(int n) {
		int prod = 1;
		for (int i = 1; i <= n; i++) {
			prod *= i;
		}
		return prod;
	}

	static int sumfac(int n) {
		int mysum = 0;
		for (char c : Integer.toString(n).toCharArray()) {
			mysum += factorial(c - '0');
		}
		return mysum;
	}

	static boolean check(int n) {
		return sumfac(n) == n;
	}

	public static void main(String args[]) {
		int mysum = 0;
		for (int i = 3; i < 100000; i++) {
			if (check(i)) mysum += i;
		}
		System.out.println(mysum);
	}
}
